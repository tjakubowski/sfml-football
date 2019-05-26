#include "CircleCollider.hpp"

namespace Football
{
	CircleCollider::CircleCollider(GameObject* gameObject, sf::Vector2f offset, float width, bool debug) : Collider(gameObject, offset, width, width, debug)
	{
	}

	float CircleCollider::getRadius() const
	{
		return width / 2;
	}

	sf::Vector2f CircleCollider::getCircleCenter() const
	{
		const auto radius = getRadius();
		return getPosition() + sf::Vector2f(radius, radius);
	}

	void CircleCollider::checkCollision(std::shared_ptr<Collider> checkCollider)
	{
		// Circle => Circle
		if (typeid(*checkCollider.get()) == typeid(CircleCollider))
		{
			const auto circleCollider = dynamic_cast<CircleCollider*>(checkCollider.get());

			const auto thisRadius = getRadius();
			const auto circleColliderRadius = circleCollider->getRadius();

			const auto sqrDistance = sqrMagnitude((circleCollider->getCircleCenter() - getCircleCenter()));
			const auto sqrRadius = (thisRadius + circleColliderRadius) * (thisRadius + circleColliderRadius);
			
			if (sqrDistance < sqrRadius)
			{
				const auto collisionPoint = getPosition() + thisRadius * normalize(checkCollider->getPosition() - getPosition());
				gameObject->onCollision(checkCollider->getGameObject(), collisionPoint);
			}
		}
		// Circle => Rectangle
		else if (typeid(*checkCollider.get()) == typeid(RectangleCollider))
		{
			const auto rectCollider = dynamic_cast<RectangleCollider*>(checkCollider.get());
			const auto circleRadius = getRadius();

			const auto nearestX = std::max(rectCollider->getPosition().x, std::min(getCircleCenter().x, rectCollider->getPosition().x + rectCollider->getWidth()));
			const auto nearestY = std::max(rectCollider->getPosition().y, std::min(getCircleCenter().y, rectCollider->getPosition().y + rectCollider->getHeight()));

			const auto deltaX = getCircleCenter().x - nearestX;
			const auto deltaY = getCircleCenter().y - nearestY;

			if ((deltaX * deltaX + deltaY * deltaY) < (circleRadius * circleRadius))
			{
				const auto collisionPoint = sf::Vector2f(nearestX, nearestY);
				gameObject->onCollision(checkCollider->getGameObject(), collisionPoint);
			}
		}
	}

	void CircleCollider::drawDebug()
	{
		sf::CircleShape circle;

		circle.setRadius(getRadius());
		circle.setOutlineColor(sf::Color::Red);
		circle.setOutlineThickness(1);
		circle.setPosition(getPosition());

		GameData::getInstance()->window.draw(circle);
	}
}
