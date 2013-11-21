#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>
#include <memory>

class Entity
{
public:
	Entity(const sf::Vector2f& position = sf::Vector2f(0.f, 0.f));

	virtual void handleInput() = 0;
	virtual void update(sf::Time delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	sf::Vector2f getPosition() const;
	std::shared_ptr<sf::Shape> getShape() const;

protected:
	sf::Vector2f position_;
	std::shared_ptr<sf::Shape> shape_;
};

#endif