#pragma once
#include "Bot.hpp"

namespace Football
{
	class Goalkeeper : public Bot
	{
	private:
		sf::Vector2f calculateGoalkeeperPosition() const;
		float maxGoalDistanceX;
		float maxGoalDistanceY;
	public:
		Goalkeeper(std::shared_ptr<Team> team);
		~Goalkeeper();
		void update(float dt) override;
	};
}
