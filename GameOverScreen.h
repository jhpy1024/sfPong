#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Screen.h"

class GameOverScreen : public Screen
{
public:
	GameOverScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Texture retryTexture_;
	sf::Sprite retrySprite_;

	sf::Texture quitTexture_;
	sf::Sprite quitSprite_;

	sf::FloatRect mouseBounds_;

	sf::SoundBuffer failBuffer_;
	sf::Sound failSound_;
};

#endif