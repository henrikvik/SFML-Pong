#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball(sf::Vector2f position, sf::Vector2f velocity);
	virtual ~Ball();


	// Inherited via GameObject
	virtual void update(float delta) override;

private:
	sf::CircleShape shape;
	sf::Vector2f velocity;

	sf::Vector2f reflect(sf::Vector2f normal);
};