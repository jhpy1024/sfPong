#include <SFML\Graphics.hpp>

#include <memory>

#include "Entity.h"

Entity::Entity(sf::Vector2f position)
	: position_(position)
{

}

sf::Vector2f Entity::getPosition() const
{
	return position_;
}

std::shared_ptr<sf::Shape> Entity::getShape() const
{
	return shape_;
}