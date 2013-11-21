#ifndef BALL_H
#define BALL_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Entity.h"

class Ball : public Entity
{
public:
	Ball(float radius);

	void handleInput() override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities) override;

	sf::FloatRect getBounds() const override;

	bool hitWall() const;
	void setHitWall(bool flag);

private:
	sf::CircleShape shape_;
	sf::Vector2f velocity_;

	sf::SoundBuffer hitSoundBuffer_;
	sf::Sound hitSound_;

	float radius_;

	sf::Vector2f getRandomVelocity();
	bool movingLeft() const;
	bool movingRight() const;

	bool hitWall_ = false;

	static const float Speed;
};

#endif