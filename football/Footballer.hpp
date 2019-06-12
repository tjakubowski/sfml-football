#pragma once
#include "GameObject.hpp"
#include "Team.hpp"

namespace Football
{
	class Team;
	class GameState;

	class Footballer : public GameObject
	{
	private:
		float nearBallDistance;
		float shootZoneDistance;
		float shootForce;
	protected:
		std::shared_ptr<Team> team;
		int goalPart;
		float ballShootDistance;
		float shootWaitTime;
		float waitToShootTime;

		bool isCloseToBall() const;
		bool isInShootDistance() const;
		void waitForShoot(float dt);
		void shoot(float force = 1);
		bool isPreparedToShoot() const;
	public:
		Footballer(sf::Vector2f position, std::shared_ptr<Team> team);
		~Footballer();

		void update(float dt) override = 0;
		void onCollision(GameObject* collisionObject) override;

		void setGoalPart(int goalPartIndex);
		float getBallDistanceSqr() const;
		bool isNearBall() const;
	};

}
