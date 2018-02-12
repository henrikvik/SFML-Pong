#include "Ball.h"

Ball::Ball(sf::Vector2f position, sf::Vector2f velocity)
{
	setPosition(position);
	setHitbox({0, 0, 32, 32});
	setShape(&shape);

	shape.setRadius(16);
	shape.setFillColor(sf::Color::White);

	this->velocity = velocity;
}

Ball::~Ball()
{
}

void Ball::update(float delta)
{
	auto position = getPosition();

	static const sf::Vector2f normal_bot(0, 1);
	static const sf::Vector2f normal_top(0, -1);
	static const sf::Vector2f normal_left(1, 0);
	static const sf::Vector2f normal_right(-1, 0);

	if (position.x > 1024 - 16) velocity = reflect(normal_right);
	if (position.x < 0) velocity = reflect(normal_left);
	if (position.y < 0) velocity = reflect(normal_top);
	if (position.y > 512 - 16) velocity = reflect(normal_bot);

	move(velocity * delta);
}

sf::Vector2f Ball::reflect(sf::Vector2f normal)
{
	float dot = normal.x * velocity.x + normal.y * velocity.y;
	return velocity - 2.f * normal * dot;
}
