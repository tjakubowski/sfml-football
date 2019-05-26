#include "GameObject.hpp"

namespace Football
{
	GameObject::GameObject() : deceleration(0.05), acceleration(0.1), maxSpeed(150)
	{

	}

	sf::Vector2f GameObject::getPosition() const
	{
		return sprite.getPosition();
	}

	std::shared_ptr<Collider> GameObject::getCollider() const
	{
		return collider;
	}

	bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b)
	{
		return a->getPosition().y < b->getPosition().y;
	}


	void GameObject::moveImmediately(sf::Vector2f moveVector)
	{
		sprite.move(moveVector);
	}

	void GameObject::move(sf::Vector2f direction, const float& dt)
	{
		// Slow down
		if (isZero(direction))
			force -= force * deceleration;
		else
			force = clampMagnitude(force + normalize(direction) * acceleration, 1);

		// Stop completely
		if (isZero(force))
			return;

		const auto finalMove = force * maxSpeed * dt;

		sprite.move(finalMove);
	}
}
