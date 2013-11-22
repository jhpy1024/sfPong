#include <SFML\Graphics.hpp>

#include "GameScreen.h"
#include "Ball.h"
#include "Game.h"
#include "Paddle.h"

GameScreen::GameScreen()
: score_(3)
{
	createEntities();
	createWalls();

	scoreFont_.loadFromFile("Fonts/arial.ttf");

	scoreText_.setFont(scoreFont_);
	scoreText_.setString(std::to_string(score_));
	scoreText_.setColor(sf::Color::Black);

	sf::FloatRect textBounds = scoreText_.getLocalBounds();

	scoreText_.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	scoreText_.setPosition(Game::Width / 2, Game::Height / 2);
}

void GameScreen::handleInput(sf::RenderWindow& window)
{
	for (auto entity : entities_)
		entity->handleInput();
}

void GameScreen::update(sf::Time delta)
{
	for (auto entity : entities_)
	{
		if (entity->getType() == Entities::Ball)
		{
			if (score_ != 0 && ((Ball*)entity.get())->hitWall())
			{
				scoreText_.setString(std::to_string(--score_));
				((Ball*)entity.get())->setHitWall(false);
			}
		}

		entity->checkCollisions(entities_);
		entity->update(delta);
	}

	updateScore();
}

void GameScreen::render(sf::RenderWindow& window)
{
	window.draw(centerWall_);
	window.draw(leftWall_);
	window.draw(rightWall_);
	window.draw(bottomWall_);
	window.draw(topWall_);

	window.draw(scoreText_);

	for (auto entity : entities_)
		entity->render(window);
}

void GameScreen::createWalls()
{
	centerWall_.setSize(sf::Vector2f(Game::WallSize, Game::Height));
	centerWall_.setPosition(Game::Width / 2 - centerWall_.getSize().x / 2, 0.f);
	centerWall_.setFillColor(sf::Color::Green);

	bottomWall_.setSize(sf::Vector2f(Game::Width, Game::WallSize));
	bottomWall_.setPosition(0.f, Game::Height - bottomWall_.getSize().y);
	bottomWall_.setFillColor(sf::Color::Green);

	topWall_.setSize(sf::Vector2f(Game::Width, Game::WallSize));
	topWall_.setPosition(0.f, 0.f);
	topWall_.setFillColor(sf::Color::Green);

	leftWall_.setSize(sf::Vector2f(Game::WallSize, Game::Height));
	leftWall_.setPosition(0.f, 0.f);
	leftWall_.setFillColor(sf::Color::Green);

	rightWall_.setSize(sf::Vector2f(Game::WallSize, Game::Height));
	rightWall_.setPosition(Game::Width - rightWall_.getSize().x, 0.f);
	rightWall_.setFillColor(sf::Color::Green);
}

void GameScreen::createEntities()
{
	entities_.push_back(std::make_shared<Paddle>(
		sf::Vector2f(15.f, 150.f),
		sf::Vector2f(Game::WallSize, Game::Height / 2 - 200 / 2)));
	entities_.push_back(std::make_shared<Ball>(10.f));
}

void GameScreen::changeWallsColor(sf::Color color)
{
	leftWall_.setFillColor(color);
	rightWall_.setFillColor(color);
	topWall_.setFillColor(color);
	bottomWall_.setFillColor(color);
	centerWall_.setFillColor(color);
}

void GameScreen::updateScore()
{
	switch (score_)
	{
	case 3:
		changeWallsColor(sf::Color::Green);
		break;
	case 2:
		changeWallsColor(sf::Color(255, 165, 0));
		break;
	case 1:
		changeWallsColor(sf::Color::Red);
		break;
	default:
		break;
	}
}