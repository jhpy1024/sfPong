#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

#include <vector>
#include <memory>

#include "Entity.h"

class Game
{
public:
	Game();

	void run();

	void handleInput();
	void update(sf::Time delta);
	void render();

	static const int Width = 640;
	static const int Height = 480;
	static const float WallSize;
	
private:
	sf::RenderWindow window_;

	sf::RectangleShape centerWall_;
	sf::RectangleShape topWall_;
	sf::RectangleShape bottomWall_;
	sf::RectangleShape leftWall_;
	sf::RectangleShape rightWall_;

	sf::Font scoreFont_;
	sf::Text scoreText_;

	std::vector<std::shared_ptr<Entity>> entities_;

	unsigned score_;

	void createEntities();
	void createWalls();
	void updateScore();
	void changeWallsColor(sf::Color color);

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};
 
#endif