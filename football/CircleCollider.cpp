#include "CircleCollider.hpp"

namespace Football
{
	CircleCollider::CircleCollider(GameObject* gameObject, sf::Vector2f offset, float width, bool debug) : Collider(gameObject, offset, width, width, debug), radius(width / 2)
	{
	}

	void CircleCollider::drawDebug()
	{
		sf::CircleShape circle;

		circle.setRadius(radius);
		circle.setOutlineColor(sf::Color::Red);
		circle.setOutlineThickness(2);
		circle.setPosition(getPosition());

		GameData::getInstance()->window.draw(circle);
	}
}
