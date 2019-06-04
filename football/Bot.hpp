#pragma once
#include "Footballer.hpp"

namespace Football
{
	class Bot : public Footballer
	{
	protected:
		float moveTowardsStopDistance;
		void moveTowards(sf::Vector2f targetPosition) const;
		void moveTowards(const float x, const float y) const;
	public:
		Bot(sf::Vector2f position);
		~Bot();
		void update(float dt) override;
	};
}
