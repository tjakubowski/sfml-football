#include "GameObject.hpp"

namespace Football
{
	GameObject::GameObject()
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
}
