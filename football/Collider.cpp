#include "Collider.hpp"

namespace Football
{
	Collider::Collider(GameObject* gameObject, sf::Vector2f offset, float width, float height, bool debug) : gameObject(gameObject), offset(offset), width(width), height(height), debug(debug)
	{
	}

	void Collider::setDebug(bool debug)
	{
		this->debug = debug;
	}

	float Collider::getWidth() const
	{
		return width;
	}

	float Collider::getHeight() const
	{
		return height;
	}

	sf::Vector2f Collider::getPosition() const
	{
		return gameObject->getPosition() + offset;
	}

	GameObject* Collider::getGameObject() const
	{
		return gameObject;
	}

	void Collider::draw()
	{
		if (debug)
			drawDebug();
	}
}