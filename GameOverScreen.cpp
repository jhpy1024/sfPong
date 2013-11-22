#include <SFML\Graphics.hpp>

#include <memory>

#include "GameOverScreen.h"
#include "GameScreen.h"
#include "Game.h"

GameOverScreen::GameOverScreen()
{
	retryTexture_.loadFromFile("Images/retry.png");
	quitTexture_.loadFromFile("Images/quit.png");

	retrySprite_.setTexture(retryTexture_);
	quitSprite_.setTexture(quitTexture_);

	retrySprite_.setPosition(Game::Width / 2 - retryTexture_.getSize().x / 2,
		Game::Height / 2 - retryTexture_.getSize().y / 2);

	quitSprite_.setPosition(retrySprite_.getPosition().x,
		retrySprite_.getPosition().y + quitTexture_.getSize().y * 1.5);

	failBuffer_.loadFromFile("Sounds/fail.wav");
	failSound_.setBuffer(failBuffer_);
	failSound_.play();

	mouseBounds_.width = 1.f;
	mouseBounds_.height = 1.f;
}

void GameOverScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mouseBounds_.intersects(retrySprite_.getGlobalBounds()))
			Game::Screen = std::make_shared<GameScreen>();
		else if (mouseBounds_.intersects(quitSprite_.getGlobalBounds()))
			window.close();
	}
}

void GameOverScreen::update(sf::Time delta)
{

}

void GameOverScreen::render(sf::RenderWindow& window)
{
	mouseBounds_.left = sf::Mouse::getPosition(window).x;
	mouseBounds_.top = sf::Mouse::getPosition(window).y;

	window.draw(retrySprite_);
	window.draw(quitSprite_);
}
