#pragma once
#include "Footballer.hpp"

namespace Football
{
	class Bot : public Footballer
	{
	protected:
		float moveTowardsStopDistance;
		void moveTowards(sf::Vector2f targetPosition) const;
	protected:
		bool canShoot() override = 0;
	public:
		Bot(sf::Vector2f position, std::shared_ptr<Team> team);
		~Bot();
		void update(float dt) override = 0;
	};
}
