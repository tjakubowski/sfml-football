#pragma once
#include "GameObject.hpp"
#include "Fan.hpp"
#include "Team.hpp"

namespace Football
{
	class Fan;

	class FansBench : public GameObject
	{
	private:
		std::vector<std::unique_ptr<Fan>> fans;

		void initFans(Team::Side& side);
	public:
		FansBench(sf::Vector2f position, Team::Side side);
		~FansBench();
		void update(float dt) override;
		void draw() override;
		void onCollision(GameObject* collisionObject) override;
	};

}
