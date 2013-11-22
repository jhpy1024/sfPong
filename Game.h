#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

#include <vector>
#include <memory>

#include "Entity.h"
#include "Screen.h"

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
	
	static std::shared_ptr<Screen> Screen;

private:
	sf::RenderWindow window_;




	

	

	
	

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};
 
#endif