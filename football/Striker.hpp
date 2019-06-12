#pragma once
#include "Bot.hpp"

namespace Football
{
	class Team;

	class Striker : public Bot
	{
	private:
		float nearBallDistance;
		float maxTimeOnEdge;
		float currentTimeOnEdge;
		bool goBack;
		bool isTeammateNearBall();
	public:
		Striker(sf::Vector2f position, std::shared_ptr<Team> team);
		~Striker();

		sf::Vector2f calculateGoalPosition() const;
		sf::Vector2f calculatePositionNearBall(float factor = 1) const;
		sf::Vector2f calculateShootPosition() const;
		sf::Vector2f getBotToBallPosition();
		bool isOnPitchEdge();
		void update(float dt) override;
		void draw() override;
	};


}
