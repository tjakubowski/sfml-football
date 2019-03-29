#include "GameObject.hpp"

namespace Football
{
	GameObject::GameObject(GameDataRef data) : data(data)
	{
	}

	GameObject::~GameObject()
	= default;

	sf::Vector2f GameObject::getPosition() const
	{
		return sprite.getPosition();
	}

	bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b)
	{
		return a->getPosition().y < b->getPosition().y;
	}
}
