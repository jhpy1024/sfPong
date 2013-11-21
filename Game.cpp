#include <SFML\Graphics.hpp>

#include <memory>
#include <string>
#include <iostream>

#include "Game.h"
#include "Ball.h"
#include "Paddle.h"

const float Game::WallSize = 20.f;

Game::Game()
: window_(sf::VideoMode(Game::Width, Game::Height), "Pong!"), score_(3)
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

void Game::createWalls()
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

void Game::createEntities()
{
	entities_.push_back(std::make_shared<Paddle>(
		sf::Vector2f(15.f, 150.f),
		sf::Vector2f(Game::WallSize, Game::Height / 2 - 200 / 2)));
	entities_.push_back(std::make_shared<Ball>(10.f));
}

void Game::updateScore()
{
	switch (score_)
	{
	case 3:
		leftWall_.setFillColor(sf::Color::Green);
		break;
	case 2:
		leftWall_.setFillColor(sf::Color(255, 165, 0));
		break;
	case 1:
		leftWall_.setFillColor(sf::Color::Red);
		break;
	default:
		break;
	}
}

void Game::handleInput()
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	for (auto entity : entities_)
		entity->handleInput();
}

void Game::update(sf::Time delta)
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

void Game::render()
{
	window_.clear();

	window_.draw(centerWall_);
	window_.draw(leftWall_);
	window_.draw(rightWall_);
	window_.draw(bottomWall_);
	window_.draw(topWall_);

	window_.draw(scoreText_);

	for (auto entity : entities_)
		entity->render(window_);

	window_.display();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}