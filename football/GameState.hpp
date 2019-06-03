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
#include "ScorePrinter.hpp"

namespace Football
{
	class Team;
	class ScorePrinter;

	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		sf::Clock clock;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		std::unique_ptr<ScorePrinter> scorePrinter;
		std::shared_ptr<b2World> world;

		std::shared_ptr<Team> teamLeft;
		std::shared_ptr<Team> teamRight;
		
		int teamLeftPoints;
		int teamRightPoints;

		void initPlayers();
		void initObjects();
		void initObstacles();

		void sortAllGameObjects();

		SFMLDebugDraw* debugDraw;
		CollisionListener* listener;

	public:
		GameState();

		void init();

		std::vector<std::shared_ptr<GameObject>> getGameObjects() const;
		std::shared_ptr<b2World> getWorld() const;

		void scorePoint(std::shared_ptr<Team>& team);

		void handleInput();
		void update(float dt);
		void draw(float dt);
	};
}
