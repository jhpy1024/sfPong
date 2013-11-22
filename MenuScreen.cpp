#include <SFML\Graphics.hpp>

#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	playTexture_.loadFromFile("Images/play.png");
	quitTexture_.loadFromFile("Images/Quit.png");

	playSprite_.setTexture(playTexture_);
	playSprite_.setPosition(Game::Width / 2 - playTexture_.getSize().x / 2,
		Game::Height / 2 - playTexture_.getSize().y / 2);

	quitSprite_.setTexture(quitTexture_);
	quitSprite_.setPosition(playSprite_.getPosition().x,
		playSprite_.getPosition().y + quitTexture_.getSize().y * 1.5);

	mouseBounds_.width = 1.f;
	mouseBounds_.height = 1.f;
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mouseBounds_.intersects(playSprite_.getGlobalBounds()))
			Game::Screen = std::make_shared<GameScreen>();
		else if (mouseBounds_.intersects(quitSprite_.getGlobalBounds()))
			window.close();
	}
}

void MenuScreen::update(sf::Time delta)
{
	
}

void MenuScreen::render(sf::RenderWindow& window)
{
	mouseBounds_.left = sf::Mouse::getPosition(window).x;
	mouseBounds_.top = sf::Mouse::getPosition(window).y;

	window.draw(playSprite_);
	window.draw(quitSprite_);
}