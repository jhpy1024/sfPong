#include <SFML\Graphics.hpp>

#include <vector>
#include <memory>

#include "AIPaddle.h"
#include "Paddle.h"
#include "Entity.h"
#include "Game.h"

AIPaddle::AIPaddle(const sf::Vector2f& size, const Ball& ball, const sf::Vector2f& position)
: Paddle(size, position), ball_(ball)
{

}

void AIPaddle::handleInput()
{

}

void AIPaddle::update(sf::Time delta)
{
	if (ball_.getVelocity().y > 0)
	{
		moveDown(delta);
	}
	else if (ball_.getVelocity().y < 0)
	{
		moveUp(delta);
	}

	shape_.setPosition(position_);
}

void AIPaddle::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}

void AIPaddle::checkCollisions(std::vector<std::shared_ptr<Entity>>& entities)
{
	if (position_.y < Game::WallSize)
		position_.y = Game::WallSize;
	else if (position_.y > Game::Height - Game::WallSize - shape_.getSize().y)
		position_.y = Game::Height - Game::WallSize - shape_.getSize().y;
}