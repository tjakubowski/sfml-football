#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"
#include "Team.hpp"
#include "Goal.hpp"
#include "Ball.hpp"
#include "Obstacle.hpp"
#include "ScoreUI.hpp"

namespace Football
{
	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		sf::Clock clock;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		std::shared_ptr<Team> leftTeam;
		std::shared_ptr<Team> rightTeam;

		void checkCollisions();
		void sortAllGameObjects();

	public:
		GameState();

		void init();
		void initPitch();
		void initObjects();
		void initTeams();

		std::vector<std::shared_ptr<GameObject>> getGameObjects() const;

		void handleInput();
		void update(float dt);
		void draw(float dt);

		std::shared_ptr<Team> getLeftTeam() const;
		std::shared_ptr<Team> getRightTeam() const;
	};
}
