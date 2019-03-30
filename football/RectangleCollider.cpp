#include "RectangleCollider.hpp"

namespace Football
{
	RectangleCollider::RectangleCollider(GameObject* gameObject, sf::Vector2f offset, float width, float height, bool debug) : Collider(gameObject, offset, width, height, debug)
	{
	}

	void RectangleCollider::checkCollision(std::shared_ptr<Collider> checkCollider)
	{
		// Rectangle => Circle
		if (typeid(*checkCollider.get()) == typeid(CircleCollider))
		{
			const auto circleCollider = dynamic_cast<CircleCollider*>(checkCollider.get());
			const auto circleRadius = circleCollider->getRadius();

			const auto deltaX = circleCollider->getCircleCenter().x - std::max(getPosition().x, std::min(circleCollider->getCircleCenter().x, getPosition().x + width));
			const auto deltaY = circleCollider->getCircleCenter().y - std::max(getPosition().y, std::min(circleCollider->getCircleCenter().y, getPosition().y + height));
			
			if ((deltaX * deltaX + deltaY * deltaY) < (circleRadius * circleRadius))
				gameObject->onCollision(checkCollider->getGameObject());
		}
		// Rectangle => Rectangle
		else if (typeid(*checkCollider.get()) == typeid(RectangleCollider))
		{
			const auto rectCollider = dynamic_cast<RectangleCollider*>(checkCollider.get());

			sf::Rect r1(getPosition(), sf::Vector2f(width, height));
			sf::Rect r2(rectCollider->getPosition(), sf::Vector2f(rectCollider->getWidth(), rectCollider->getHeight()));

			if(r1.intersects(r2))
				gameObject->onCollision(checkCollider->getGameObject());
		}
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
