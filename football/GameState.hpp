#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Bot.hpp"
#include "Obstacle.hpp"
#include "Goal.hpp"
#include "Team.hpp"
#include "CollisionListener.hpp"
#include "SFMLDebugDraw.h"

namespace Football
{
	class Team;

	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		sf::Clock clock;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		std::shared_ptr<b2World> world;

		std::shared_ptr<Team> teamLeft;
		std::shared_ptr<Team> teamRight;

		void sortAllGameObjects();
		void initPlayers();
		void initObjects();
		void initObstacles();

		SFMLDebugDraw* debugDraw;
		CollisionListener* listener;

	public:
		GameState();

		void init();

		std::vector<std::shared_ptr<GameObject>> getGameObjects() const;
		std::shared_ptr<b2World> getWorld() const;

		void handleInput();
		void update(float dt);
		void draw(float dt);
	};
}
