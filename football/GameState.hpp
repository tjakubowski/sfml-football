#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Striker.hpp"
#include "Goalkeeper.hpp"
#include "Obstacle.hpp"
#include "Ball.hpp"
#include "Goal.hpp"
#include "Team.hpp"
#include "FansBench.hpp"
#include "CollisionListener.hpp"
#include "SFMLDebugDraw.h"
#include "MatchTimer.hpp"
#include "ScorePrinter.hpp"
#include "UIContainer.hpp"

namespace Football
{
	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		sf::Clock clock;
		bool multiplayer;
		bool debug;
		bool pause;
		bool ended;
		bool reset;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		struct PitchSize
		{
			float sidesWidth = 11.f;
			float sidesWidthBig = 43.f;
			float sidesHeight = 235.f;
			float sidesHeightBig = 303.f;
			float bottomHeight = 17.f;
			float topHeight = 86.f;
			float goalWidth = 43.f;
			float goalHeight = 158.f;
			float cornerSize = 50.f;
		} pitchSize;

		std::unique_ptr<UIContainer> menuManager;
		std::unique_ptr<UIContainer> uiManager;

		std::shared_ptr<MatchTimer> matchTimer;
		std::shared_ptr<ScorePrinter> scorePrinter;
		std::shared_ptr<b2World> world;

		std::shared_ptr<Ball> ball;
		std::shared_ptr<Team> teamLeft;
		std::shared_ptr<Team> teamRight;

		int teamLeftPoints;
		int teamRightPoints;

		void initGameObjects();
		void initObstacles();
		void initUI();

		std::shared_ptr<Obstacle> createObstacle(sf::Vector2f position, sf::Vector2f dimensions, float angleDegrees = 0);
		std::shared_ptr<Goal> createGoal(sf::Vector2f position, std::shared_ptr<Team> team);
		std::shared_ptr<Striker> createStriker(sf::Vector2f position, std::shared_ptr<Team> team);
		std::shared_ptr<Goalkeeper> createGoalkeeperBot(std::shared_ptr<Team> team);
		std::shared_ptr<Player> createPlayer(sf::Vector2f position, std::shared_ptr<Team> team, AxisKeys keys = { sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Space });

		void sortAllGameObjects();

		SFMLDebugDraw* debugDraw;
		CollisionListener* listener;

	public:
		GameState(const bool multiplayer = false);

		void init() override;

		std::shared_ptr<Ball> getBall() const;
		std::shared_ptr<Team> getTeam(Team::Side side) const;
		std::vector<std::shared_ptr<GameObject>> getGameObjects() const;
		std::shared_ptr<b2World> getWorld() const;

		void scoreGoal(Team::Side side);
		void resetGameObjectsPositions();
		void endGame();

		void update(float dt) override;
		void draw(float dt) override;
	};
}
