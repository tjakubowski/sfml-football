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
		float ballShootDistance;
		float shootForce;
	protected:
		std::shared_ptr<Team> team;
		bool isCloseToBall() const;
		bool isInShootDistance() const;
		virtual bool canShoot() = 0;
		void shoot() const;
		int goalPart;
	public:
		Footballer(sf::Vector2f position, std::shared_ptr<Team> team);
		~Footballer();
		
		void update(float dt) override = 0;
		void onCollision(GameObject* collisionObject) override;

		void setGoalPart(int goalPartIndex);
		bool isNearBall() const;
	};

}
