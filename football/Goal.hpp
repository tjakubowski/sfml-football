#pragma once
#include "GameObject.hpp"
#include "RectangleCollider.hpp"
#include "Team.hpp"
#include "GameState.hpp"

namespace Football
{
	class Goal : public GameObject
	{
	private:
		std::shared_ptr<Team> team;
	public:
		Goal(sf::Vector2f position, std::shared_ptr<Team> team);
		~Goal();
		void draw() override;
		void update(float dt) override;
		void onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint) override;
	};

}
