#pragma once
#include "GameObject.hpp"
#include "Team.hpp"
#include "GameState.hpp"

namespace Football
{
	class Team;

	class Goal : public GameObject
	{
	private:
		Team* team;
	public:
		Goal(sf::Vector2f position, float width, float height);
		~Goal();

		void setTeam(Team* team);

		void update(float dt) override;
		void draw() override;
		void onCollision(GameObject* collisionObject) override;
	};
}
