#pragma once
#include "Bot.hpp"

namespace Football
{
	class Team;

	class Striker : public Bot
	{
	private:
		float nearBallDistance;
		bool isTeammateNearBall();
	protected:
		bool canShoot() override;
	public:
		Striker(sf::Vector2f position, std::shared_ptr<Team> team);
		~Striker();

		sf::Vector2f calculateGoalPosition() const;
		sf::Vector2f calculatePositionNearBall() const;
		sf::Vector2f calculateShootPosition() const;
		void update(float dt) override;
	};


}
