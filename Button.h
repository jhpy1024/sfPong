#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>

#include <string>

class Button
{
public:
	Button(const std::string& imageFile, sf::Vector2f position = sf::Vector2f(0, 0));

	void render(sf::RenderWindow& window);

	sf::FloatRect getBounds() const;

	void(*callBack)();

private:
	sf::Vector2f position_;
	sf::Texture texture_;
	sf::Sprite sprite_;
};

#endif