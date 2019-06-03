#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"

namespace Football
{
	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		sf::Clock clock;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		void sortAllGameObjects();
		void initPlayers();
		void initObjects();

		SFMLDebugDraw* debugDraw;

	public:
		GameState();

		void init();

		std::vector<std::shared_ptr<GameObject>> getGameObjects() const;

		void handleInput();
		void update(float dt);
		void draw(float dt);
	};
}
