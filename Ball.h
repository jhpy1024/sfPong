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

	void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities) override;

	sf::FloatRect getBounds() const override;

private:
	sf::CircleShape shape_;
	sf::Vector2f velocity_;

	float radius_;

	sf::Vector2f getRandomVelocity();
	bool movingLeft() const;
	bool movingRight() const;

	static const float Speed;
};

#endif