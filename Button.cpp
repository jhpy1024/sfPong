#include <SFML\Graphics.hpp>

#include <string>

#include "Button.h"

Button::Button(const std::string& imageName, sf::Vector2f position)
: position_(position)
{
	texture_.loadFromFile(imageName);
	sprite_.setTexture(texture_);
	sprite_.setPosition(position_);
}

sf::FloatRect Button::getBounds() const
{
	return sprite_.getGlobalBounds();
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(sprite_);
}