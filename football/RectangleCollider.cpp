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

			const auto nearestX = std::max(getPosition().x, std::min(circleCollider->getCircleCenter().x, getPosition().x + width));
			const auto nearestY = std::max(getPosition().y, std::min(circleCollider->getCircleCenter().y, getPosition().y + height));

			const auto deltaX = circleCollider->getCircleCenter().x - nearestX;
			const auto deltaY = circleCollider->getCircleCenter().y - nearestY;
			
			if ((deltaX * deltaX + deltaY * deltaY) < (circleRadius * circleRadius))
			{
				const auto collisionPoint = sf::Vector2f(nearestX, nearestY);
				gameObject->onCollision(checkCollider->getGameObject(), collisionPoint);
			}
		}
		// Rectangle => Rectangle
		else if (typeid(*checkCollider.get()) == typeid(RectangleCollider))
		{
			const auto rectCollider = dynamic_cast<RectangleCollider*>(checkCollider.get());

			const sf::Rect<float> r1(getPosition(), sf::Vector2f(width, height));
			const sf::Rect<float> r2(rectCollider->getPosition(),
			                         sf::Vector2f(rectCollider->getWidth(), rectCollider->getHeight()));

			sf::Rect<float> intersectionRect;
			if(r1.intersects(r2, intersectionRect))
			{
				const auto collisionPoint = sf::Vector2f(intersectionRect.left + intersectionRect.width/2, intersectionRect.top + intersectionRect.height/2);
				gameObject->onCollision(checkCollider->getGameObject(), collisionPoint);
			}
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
