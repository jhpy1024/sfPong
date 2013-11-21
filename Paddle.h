#ifndef PADDLE_H
#define PADDLE_H

#include <SFML\Graphics.hpp>

#include "Entity.h"

class Paddle : public Entity
{
public:
	Paddle(const sf::Vector2f& size, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f));

	void handleInput() override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void moveUp(sf::Time delta);
	void moveDown(sf::Time delta);

	void checkCollisions();

	float getWidth() const;
	float getHeight() const;

private:
	sf::RectangleShape shape_;
	sf::Vector2f size_;

	bool upPressed_;
	bool downPressed_;

	static const int Speed = 100;
};

#endif