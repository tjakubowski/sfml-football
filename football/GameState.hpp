#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "AttackerBot.hpp"
#include "Goalkeeper.hpp"
#include "Obstacle.hpp"
#include "Ball.hpp"
#include "Goal.hpp"
#include "Team.hpp"
#include "CollisionListener.hpp"
#include "SFMLDebugDraw.h"
#include "ScorePrinter.hpp"
#include "MatchTimer.hpp"
#include "UIManager.hpp"

namespace Football
{
	class ScorePrinter;
	class MatchTimer;

	class GameState : public State
	{
	private:
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		sf::Clock clock;
		bool ended;

		sf::Texture backgroundTexture;
		sf::Sprite background;

		float goalWidth;
		float goalHeight;

		std::unique_ptr<UIManager> uiManager;
		std::unique_ptr<MatchTimer> matchTimer;
		std::unique_ptr<ScorePrinter> scorePrinter;
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
		std::shared_ptr<AttackerBot> createAttackerBot(sf::Vector2f position, std::shared_ptr<Team> team);
		std::shared_ptr<Goalkeeper> createGoalkeeperBot(std::shared_ptr<Team> team);
		std::shared_ptr<Player> createPlayer(sf::Vector2f position, std::shared_ptr<Team> team);

		void sortAllGameObjects();

		SFMLDebugDraw* debugDraw;
		CollisionListener* listener;

	public:
		GameState();

		void init() override;

		std::shared_ptr<Ball> getBall() const;
		std::shared_ptr<Team> getTeam(Team::Side side) const;
		std::vector<std::shared_ptr<GameObject>> getGameObjects() const;
		std::shared_ptr<b2World> getWorld() const;

		void scoreGoal(Team::Side side);
		void endGame();

		void handleInput() override;
		void update(float dt) override;
		void draw(float dt) override;
	};
}
