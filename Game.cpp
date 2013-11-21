#include <SFML\Graphics.hpp>

#include <memory>

#include "Game.h"
#include "Paddle.h"

Game::Game()
: window_(sf::VideoMode(Game::Width, Game::Height), "Pong!")
{
	entities_.push_back(std::make_shared<Paddle>(sf::Vector2f(15.f, 150.f),
		sf::Vector2f(10, 100)));
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
		entity->update(delta);
}

void Game::render()
{
	window_.clear();

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