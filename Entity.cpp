#include <SFML\Graphics.hpp>

#include <memory>

#include "Entity.h"

Entity::Entity(const sf::Vector2f& position)
: position_(position)
{

}

sf::Vector2f Entity::getPosition() const
{
	return position_;
}