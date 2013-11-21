#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

class Game
{
public:
	Game();

	void run();

	void handleInput();
	void update(sf::Time delta);
	void render();

private:
	sf::RenderWindow window_;

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	static const int Width = 640;
	static const int Height = 480;
};

#endif