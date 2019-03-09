#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"

namespace Football
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		Player *player;
	};
}
