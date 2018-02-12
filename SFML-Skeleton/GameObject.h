#pragma once
#include <SFML\Graphics.hpp>

class GameObject : public sf::Drawable
{
public:
	GameObject();
	virtual ~GameObject();

	bool checkCollision(GameObject const& other) const;
	virtual void update(float delta) = 0;

	void move(sf::Vector2f const& offset);

	void setPosition(sf::Vector2f position);
	void setHitbox(sf::FloatRect hitbox);
	void setShape(sf::Shape * shape);

	sf::Vector2f getPosition() const;
	sf::Shape* getShape() const { return shape; };


	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::Vector2f position;
	sf::Shape * shape;
	sf::FloatRect hitbox;

};