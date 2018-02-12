#include "Game.h"

Game::Game()
	: window(sf::VideoMode(1024, 512), "Pong")
	, ball({ 512, 256 }, {100,100})
{
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		update(clock.restart().asSeconds());

		window.clear();
		draw();
		window.display();
	}
}

void Game::update(float delta)
{
	ball.update(delta);
}

void Game::draw()
{
	window.draw(ball);
}
