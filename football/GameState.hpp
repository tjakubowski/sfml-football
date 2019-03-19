#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"
#include "Team.hpp"

namespace Football
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void init();
		void initTeams();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;
		void sortAllGameObjects();

		GameDataRef _data;

		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;



		std::unique_ptr<Team> leftTeam;
		std::unique_ptr<Team> rightTeam;
	};
}
