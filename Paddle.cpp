#include <SFML\Graphics.hpp>

#include "Paddle.h"
#include "Entity.h"
#include "Game.h"

const float Paddle::Speed = 200.f;

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

void Paddle::checkCollisions()
{
	if (position_.y < 0)
		position_.y = 0.f;
	if (position_.y > Game::Height - size_.y)
		position_.y = Game::Height - size_.y;
}

void Paddle::update(sf::Time delta)
{
	checkCollisions();

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