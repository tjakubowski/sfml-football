#pragma once
#include "Bot.hpp"
#include "Goal.hpp"

namespace Football
{
	class Goalkeeper : public Football::Bot
	{
	private:
		sf::Vector2f startPosition;

		sf::Vector2f calculateGoalkeeperPosition();
	public:
		enum Side { Left, Right };
		Goalkeeper(std::shared_ptr<Goal> goal, Side side);
		~Goalkeeper();
	};
}
