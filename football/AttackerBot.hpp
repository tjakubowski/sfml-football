#pragma once
#include "Bot.hpp"

namespace Football
{
	class Team;

	class AttackerBot : public Bot
	{
	private:
		bool isTeammateNearBall();
	public:
		AttackerBot(sf::Vector2f position, std::shared_ptr<Team> team);
		~AttackerBot();

		sf::Vector2f calculateGoalPosition() const;
		sf::Vector2f calculatePositionNearBall() const;
		sf::Vector2f calculateShootPosition() const;
		void update(float dt) override;
	};


}
