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
				gameObject->onCollision(checkCollider->getGameObject());
		}
		// Circle => Rectangle
		else if (typeid(*checkCollider.get()) == typeid(RectangleCollider))
		{
			const auto rectCollider = dynamic_cast<RectangleCollider*>(checkCollider.get());
			const auto circleRadius = getRadius();

			const auto deltaX = getCircleCenter().x - std::max(rectCollider->getPosition().x, std::min(getCircleCenter().x, rectCollider->getPosition().x + rectCollider->getWidth()));
			const auto deltaY = getCircleCenter().y - std::max(rectCollider->getPosition().y, std::min(getCircleCenter().y, rectCollider->getPosition().y + rectCollider->getHeight()));

			if ((deltaX * deltaX + deltaY * deltaY) < (circleRadius * circleRadius))
				gameObject->onCollision(checkCollider->getGameObject());
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
