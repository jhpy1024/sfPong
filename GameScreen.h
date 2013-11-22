#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML\Graphics.hpp>

#include <memory>

#include "Entity.h"
#include "Screen.h"

class GameScreen : public Screen
{
public:
	GameScreen();

	void handleInput() override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	void updateScore();
	void changeWallsColor(sf::Color color);
	void createEntities();
	void createWalls();

	std::vector<std::shared_ptr<Entity>> entities_;

	unsigned score_;

	sf::Font scoreFont_;
	sf::Text scoreText_;

	sf::RectangleShape centerWall_;
	sf::RectangleShape topWall_;
	sf::RectangleShape bottomWall_;
	sf::RectangleShape leftWall_;
	sf::RectangleShape rightWall_;
};

#endif
