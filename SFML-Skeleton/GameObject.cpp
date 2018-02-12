#include "GameObject.h"

GameObject::GameObject()
{
	this->shape = nullptr;
}

GameObject::~GameObject()
{
}


bool GameObject::checkCollision(GameObject const & other) const
{
	sf::FloatRect hb0 = hitbox;
	hb0.left += position.x;
	hb0.top += position.y;
	sf::FloatRect hb1 = other.hitbox;
	hb1.left += other.position.x;
	hb1.top += other.position.y;

	return hb0.intersects(hb1);
}

void GameObject::move(sf::Vector2f const & offset)
{
	this->position += offset;
	if (this->shape)
	{
		this->shape->setPosition(this->position);
	}
}

void GameObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void GameObject::setHitbox(sf::FloatRect hitbox)
{
	this->hitbox = hitbox;
}

void GameObject::setShape(sf::Shape * shape)
{
	this->shape = shape;
}

sf::Vector2f GameObject::getPosition() const
{
	return this->position;
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (this->shape)
	{
		target.draw(*this->shape);
	}

#ifdef _DEBUG
	sf::Vector2f dbgRectOffset(hitbox.left, hitbox.top);
	sf::RectangleShape dbgRect;
	dbgRect.setPosition(position + dbgRectOffset);
	dbgRect.setOutlineColor(sf::Color::Red);
	dbgRect.setOutlineThickness(1);

	target.draw(dbgRect);
#endif
}