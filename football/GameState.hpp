#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"
#include "Team.hpp"

namespace Football
{
	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;
		void sortAllGameObjects();

		sf::Clock clock;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		std::unique_ptr<Team> leftTeam;
		std::unique_ptr<Team> rightTeam;

	public:
		GameState();

		void init();
		void initTeams();

		void handleInput();
		void update(float dt);
		void draw(float dt);
	};
}
