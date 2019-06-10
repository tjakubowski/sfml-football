#include "Fan.hpp"

namespace Football
{
	Fan::Fan(sf::Vector2f position, Team::Side& side) : GameObject(position, b2_staticBody)
	{
		if (side == Team::Side::Left)
			animation = std::make_unique<Animation>("fan_blue", &sprite, 4, .2f, randomBetween(0.f, .3f));
		else
			animation = std::make_unique<Animation>("fan_red", &sprite, 4, .2f, randomBetween(0.f, .3f));

		GameObject::setSpriteTextureOrigin();

		tag = "fan";
	}

	Fan::~Fan()
	{
	}

	void Fan::update(float dt)
	{
		animation->update(dt);
	}

	void Fan::onCollision(GameObject* collisionObject)
	{
	}
}
