#include <SFML\Graphics.hpp>

#include <memory>
#include <string>
#include <iostream>

#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "GameScreen.h"
#include "MenuScreen.h"

const float Game::WallSize = 20.f;
std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();

Game::Game()
: window_(sf::VideoMode(Game::Width, Game::Height), "Pong!")
{
	
}

void Game::handleInput()
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	Game::Screen->handleInput();
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::render()
{
	window_.clear();
	Game::Screen->render(window_);
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