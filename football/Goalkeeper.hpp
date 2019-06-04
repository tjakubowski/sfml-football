#pragma once
#include "Bot.hpp"
#include "Goal.hpp"

namespace Football
{
	class Goalkeeper : public Bot
	{
	public:
		enum Side { Left, Right };
	private:
		sf::Vector2f calculateGoalkeeperPosition();
		float maxGoalDistanceX;
		float maxGoalDistanceY;
		Side side;
	public:
		Goalkeeper(std::shared_ptr<Goal> goal, Side side);
		~Goalkeeper();
		void update(float dt) override;
	};
}
