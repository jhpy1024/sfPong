#include <SFML\Graphics.hpp>

#include <vector>
#include <memory>

#include "Paddle.h"
#include "Entity.h"
#include "Game.h"

const float Paddle::Speed = 300.f;

Paddle::Paddle(const sf::Vector2f& size, const sf::Vector2f& position)
: Entity(Entities::Paddle, position), size_(size)
{
	shape_.setSize(size);
	shape_.setFillColor(sf::Color::White);
	shape_.setPosition(position);
}

void Paddle::handleInput()
{
	upPressed_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	downPressed_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void Paddle::moveUp(sf::Time delta)
{
	position_.y -= Paddle::Speed * delta.asSeconds();
}

void Paddle::moveDown(sf::Time delta)
{
	position_.y += Paddle::Speed * delta.asSeconds();
}

void Paddle::checkCollisions(std::vector<std::shared_ptr<Entity>>& entities)
{
	if (position_.y < Game::WallSize)
		position_.y = Game::WallSize;
	if (position_.y > Game::Height - Game::WallSize - size_.y)
		position_.y = Game::Height - Game::WallSize - size_.y;
}

void Paddle::update(sf::Time delta)
{
	if (upPressed_)
		moveUp(delta);
	if (downPressed_)
		moveDown(delta);

	shape_.setPosition(position_);
}

void Paddle::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}

sf::FloatRect Paddle::getBounds() const
{
	return shape_.getGlobalBounds();
}