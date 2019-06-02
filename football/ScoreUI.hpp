#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Team.hpp"
#include <sstream>

namespace Football
{
	class ScoreUI : public GameObject
	{
	private:
		std::stringstream ss;
		sf::Text text;
		std::shared_ptr<Team> leftTeam;
		std::shared_ptr<Team> rightTeam;
	public:
		ScoreUI(sf::Vector2f position, std::shared_ptr<Team> leftTeam, std::shared_ptr<Team> rightTeam);
		~ScoreUI();
		void draw() override;
		void update(float dt) override;
		void onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint) override;
	};
}
