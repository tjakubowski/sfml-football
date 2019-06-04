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
		std::shared_ptr<Team> team;
		float width;
		float height;
	public:
		Goal(sf::Vector2f position, float width, float height);
		~Goal();

		void setTeam(std::shared_ptr<Team>& team);

		void update(float dt) override;
		void draw() override;
		void onCollision(GameObject* collisionObject) override;
		float getWidth() const override;
		float getHeight() const override;
	};
}
