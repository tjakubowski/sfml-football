#include "RectangleCollider.hpp"

namespace Football
{
	RectangleCollider::RectangleCollider(GameObject* gameObject, sf::Vector2f offset, float width, float height, bool debug) : Collider(gameObject, offset, width, height, debug)
	{
	}

	void RectangleCollider::drawDebug()
	{
		sf::RectangleShape rectangle;

		rectangle.setSize(sf::Vector2f(width, height));
		rectangle.setOutlineColor(sf::Color::Red);
		rectangle.setOutlineThickness(2);
		rectangle.setPosition(getPosition());

		GameData::getInstance()->window.draw(rectangle);
	}
}
