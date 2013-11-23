#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>

#include <string>

class Button
{
public:
	Button() = default;
	Button(const std::string& imageFile, sf::Vector2f position = sf::Vector2f(0, 0));

	void render(sf::RenderWindow& window);

	sf::FloatRect getBounds() const;
	sf::Vector2u getSize() const;
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	void(*callBack)();

private:
	sf::Vector2f position_;
	sf::Texture texture_;
	sf::Sprite sprite_;
};

#endif