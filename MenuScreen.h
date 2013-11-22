#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML\Graphics.hpp>

#include "Screen.h"

class MenuScreen : public Screen
{
public:
	MenuScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Texture playTexture_;
	sf::Sprite playSprite_;

	sf::Texture quitTexture_;
	sf::Sprite quitSprite_;

	sf::FloatRect mouseBounds_;
};

#endif