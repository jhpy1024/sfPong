#include <SFML\Graphics.hpp>

#include <memory>

#include "Entity.h"

Entity::Entity(Entities::EntityType type, const sf::Vector2f& position)
: type_(type), position_(position)
{

}

sf::Vector2f Entity::getPosition() const
{
	return position_;
}

Entities::EntityType Entity::getType() const
{
	return type_;
}