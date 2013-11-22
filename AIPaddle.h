#ifndef AIPADDLE_H
#define AIPADDLE_H

#include <SFML\Graphics.hpp>

#include <vector>
#include <memory>

#include "Entity.h"
#include "Ball.h"
#include "Paddle.h"

class AIPaddle : public Paddle
{
public:
	AIPaddle(const sf::Vector2f& size, const Ball& ball,
		const sf::Vector2f& position = sf::Vector2f(0.f, 0.f));

	void handleInput() override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities) override;

private:
	const Ball& ball_;

	float distanceToBall() const;
};

#endif