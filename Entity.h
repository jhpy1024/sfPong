#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>

#include <memory>
#include <vector>

namespace Entities
{
	enum EntityType
	{
		Paddle,
		Ball,
		None
	};
}


class Entity
{
public:
	Entity(Entities::EntityType type, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f));

	virtual void handleInput() = 0;
	virtual void update(sf::Time delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities) = 0;

	virtual sf::FloatRect getBounds() const = 0;
	sf::Vector2f getPosition() const;
	Entities::EntityType getType() const;

protected:
	sf::Vector2f position_;

	Entities::EntityType type_ = Entities::None;
};

#endif