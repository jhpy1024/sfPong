#include <SFML\Graphics.hpp>

#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "MenuScreen.h"

MenuScreen::MenuScreen()
: playBtn_("Images/play.png"), quitBtn_("Images/quit.png")
{
	//quitSprite_.setPosition(playSprite_.getPosition().x,
	//	playSprite_.getPosition().y + quitTexture_.getSize().y * 1.5);
	playBtn_.callBack = [](){ Game::Screen = std::make_shared<GameScreen>(); };
	playBtn_.setPosition(Game::Width / 2 - playBtn_.getSize().x / 2,
		Game::Height / 2 - playBtn_.getSize().y / 2);

	btnManager_.addButton("play", std::make_shared<Button>(playBtn_));
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{
	btnManager_.update(window);
}

void MenuScreen::update(sf::Time delta)
{
	
}

void MenuScreen::render(sf::RenderWindow& window)
{
	btnManager_.render(window);
}