#pragma once
#include "GameObject.hpp"
#include "Team.hpp"
#include "FansBench.hpp"

namespace Football
{
	class Fan : public GameObject
	{
	public:
		Fan(sf::Vector2f position, Team::Side& side);
		~Fan();
		void update(float dt) override;
		void onCollision(GameObject* collisionObject) override;
	};
}
