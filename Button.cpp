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

sf::Vector2u Button::getSize() const
{
	return texture_.getSize();
}

sf::FloatRect Button::getBounds() const
{
	return sprite_.getGlobalBounds();
}

sf::Vector2f Button::getPosition() const
{
	return sprite_.getPosition();
}

void Button::setPosition(sf::Vector2f position)
{
	sprite_.setPosition(position);
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(sprite_);
}