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
	public:
		GameState(GameDataRef data);

		void Init();
		void InitTeams();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		std::vector<std::shared_ptr<Footballer>> GetAllFootballers() const;
		std::vector<std::shared_ptr<Footballer>> GetAllFootballersSorted() const;

		GameDataRef _data;

		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		std::unique_ptr<Team> leftTeam;
		std::unique_ptr<Team> rightTeam;
	};
}
