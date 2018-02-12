#pragma once
#include <SFML\Graphics.hpp>

#include "Ball.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void run();

private:
	sf::RenderWindow window;

	Ball ball;

	void update(float delta);
	void draw();
};