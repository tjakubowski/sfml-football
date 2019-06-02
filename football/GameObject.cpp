#include "GameObject.hpp"

namespace Football
{
	GameObject::GameObject(sf::Vector2f position) : deceleration(0.05), acceleration(0.1), maxSpeed(150)
	{
		sprite.setPosition(position);
	}

	std::string GameObject::getTag() const
	{
		return tag;
	}

	std::shared_ptr<Collider> GameObject::getCollider() const
	{
		return collider;
	}

	bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b)
	{
		return a->getPosition().y < b->getPosition().y;
	}
}
