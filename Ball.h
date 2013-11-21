#ifndef BALL_H
#define BALL_H

#include <SFML\Graphics.hpp>

#include "Entity.h"

class Ball : public Entity
{
public:
	Ball(float radius);

	void handleInput() override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void checkCollisions();

private:
	sf::CircleShape shape_;
	sf::Vector2f velocity_;

	float radius_;

	sf::Vector2f getRandomVelocity();

	static const float Speed;
};

#endif