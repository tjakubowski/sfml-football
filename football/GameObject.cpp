#include "GameObject.hpp"

namespace Football
{
	GameObject::GameObject(GameDataRef data) : data(data)
	{
	}

	GameObject::~GameObject()
	= default;

	bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b)
	{
		return a->position.y < b->position.y;
	}
}
