#include <SFML\Graphics.hpp>

#include <string>

#include "ButtonManager.h"

ButtonManager::ButtonManager()
{
	mouseBounds_.width = 1.f;
	mouseBounds_.height = 1.f;
}

void ButtonManager::update(sf::RenderWindow& window)
{
	mouseBounds_.left = sf::Mouse::getPosition(window).x;
	mouseBounds_.top = sf::Mouse::getPosition(window).y;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
		{
			if (mouseBounds_.intersects(it->second->getBounds()))
				it->second->callBack();
		}
	}
}

void ButtonManager::render(sf::RenderWindow& window)
{
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		it->second->render(window);
	}
}

void ButtonManager::addButton(const std::string& id, std::shared_ptr<Button>& button)
{
	buttons_[id] = button;
}

void ButtonManager::removeButton(const std::string& id)
{
	buttons_.erase(id);
}