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

	sf::Vector2f Collider::getPosition() const
	{
		return gameObject->getPosition() + offset;
	}

	void Collider::draw()
	{
		if (debug)
			drawDebug();
	}
}