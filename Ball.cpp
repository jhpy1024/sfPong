#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <random>
#include <vector>
#include <memory>
#include <ctime>

#include "Ball.h"
#include "Entity.h"
#include "Game.h"

const float Ball::Speed = 480.f;

Ball::Ball(float radius)
: Entity(Entities::Ball, sf::Vector2f(Game::Width / 2 - radius, Game::Height / 2 - radius)),
radius_(radius), velocity_(getRandomVelocity())
{
	shape_.setRadius(radius_);
	shape_.setPosition(position_);
	shape_.setFillColor(sf::Color::Red);

	hitSoundBuffer_.loadFromFile("Sounds/hit_sound.wav");
	hitSound_.setBuffer(hitSoundBuffer_);
}

sf::Vector2f Ball::getRandomVelocity()
{
	sf::Vector2f vel;

	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_real_distribution<float> distribution(-1.f, 1.f);

	vel.x = distribution(engine);
	vel.y = distribution(engine);

	return vel;
}

void Ball::handleInput()
{

}

void Ball::checkCollisions(std::vector<std::shared_ptr<Entity>>& entities)
{
	if (position_.x >= Game::Width - Game::WallSize - radius_ * 2)
	{
		velocity_.x = -velocity_.x;
		hitSound_.play();
	}
	if (position_.x <= Game::WallSize)
	{
		velocity_.x = -velocity_.x;
		hitSound_.play();
	}
	if (position_.y <= Game::WallSize)
	{
		velocity_.y = -velocity_.y;
		hitSound_.play();
	}
	if (position_.y >= Game::Height - Game::WallSize - radius_ * 2)
	{
		velocity_.y = -velocity_.y;
		hitSound_.play();
	}

	for (auto entity : entities)
	{
		if (entity->getType() != type_)
		{
			if (entity->getBounds().intersects(getBounds()))
			{
				hitSound_.play();

				while (entity->getBounds().intersects(getBounds()))
				{
					if (movingLeft())
					{
						position_.x += 1.f;
						shape_.setPosition(position_);
					}
					else if (movingRight())
					{
						position_.x -= 1.f;
						shape_.setPosition(position_);
					}
				}

				velocity_.x = -velocity_.x;
			}
		}
	}
}

void Ball::update(sf::Time delta)
{
	position_ += velocity_ * Ball::Speed * delta.asSeconds();

	shape_.setPosition(position_);
}

void Ball::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}

bool Ball::movingLeft() const
{
	return velocity_.x < 0.f;
}

bool Ball::movingRight() const
{
	return velocity_.x > 0.f;
}

sf::FloatRect Ball::getBounds() const
{
	return shape_.getGlobalBounds();
}
