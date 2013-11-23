#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML\Graphics.hpp>

#include "Screen.h"
#include "Button.h"
#include "ButtonManager.h"

class MenuScreen : public Screen
{
public:
	MenuScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	ButtonManager btnManager_;
	Button playBtn_;
	Button quitBtn_;
};

#endif