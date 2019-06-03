#include "GameState.hpp"
#include "Ball.hpp"
#include "Bot.hpp"
#include "Obstacle.hpp"
#include "Goal.hpp"

namespace Football
{
	GameState::GameState()
	{
	}

	void GameState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Football pitch", TEX_FOOTBALL_PITCH);
		GameData::getInstance()->assets.LoadTexture("Footballer", TEX_FOOTBALLER);
		GameData::getInstance()->assets.LoadTexture("Player", TEX_PLAYER);
		GameData::getInstance()->assets.LoadTexture("Ball", TEX_BALL);

		GameData::getInstance()->assets.LoadFont("RobotoMedium", FONT_ROBOTO_MEDIUM);

		background.setTexture(GameData::getInstance()->assets.GetTexture("Football pitch"));

		debugDraw = new SFMLDebugDraw(GameData::getInstance()->window);
		GameData::getInstance()->worldManager.getWorld()->SetDebugDraw(debugDraw);
		uint32 flags = 0;
		flags += b2Draw::e_jointBit;
		flags += b2Draw::e_aabbBit;
		flags += b2Draw::e_centerOfMassBit;
		flags += b2Draw::e_pairBit;
		flags += b2Draw::e_shapeBit;
		debugDraw->SetFlags(flags);

		initPlayers();
		initObjects();
		initObstacles();
	}

	void GameState::initPlayers()
	{
		const auto player = std::make_shared<Player>(sf::Vector2f(150, 150));
		gameObjects.push_back(player);

		const auto bot = std::make_shared<Bot>(sf::Vector2f(20, 20));
		gameObjects.push_back(bot);
	}

	void GameState::initObjects()
	{
		const float goalWidth = 30.f;
		const float goalHeight = 147.f;

		const auto ball = std::make_shared<Ball>(sf::Vector2f(300, 300));
		gameObjects.push_back(ball);

		const auto goalLeft = std::make_shared<Goal>(
			sf::Vector2f(10, 220),
			goalWidth,
			goalHeight
			);

		const auto goalRight = std::make_shared<Goal>(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 10 - goalWidth, 220),
			goalWidth,
			goalHeight
			);

		gameObjects.push_back(goalLeft);
		gameObjects.push_back(goalRight);
	}

	void GameState::initObstacles()
	{
		const auto obstacleTop = std::make_shared<Obstacle>(
			sf::Vector2f(0, 0),
			GameData::getInstance()->window.getSize().x,
			15
			);

		const auto obstacleBottom = std::make_shared<Obstacle>(
			sf::Vector2f(0, GameData::getInstance()->window.getSize().y - 15),
			GameData::getInstance()->window.getSize().x,
			15
			);

		const auto obstacleLeft = std::make_shared<Obstacle>(
			sf::Vector2f(0, 0),
			10,
			GameData::getInstance()->window.getSize().y
			);

		const auto obstacleRight = std::make_shared<Obstacle>(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 10, 0),
			10,
			GameData::getInstance()->window.getSize().y
			);

		const auto obstacleTopLeft = std::make_shared<Obstacle>(
			sf::Vector2f(0, 0),
			40,
			220
			);

		const auto obstacleBottomLeft = std::make_shared<Obstacle>(
			sf::Vector2f(0, 367),
			40,
			220
			);

		const auto obstacleTopRight = std::make_shared<Obstacle>(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 40, 0),
			40,
			220
			);

		const auto obstacleBottomRight = std::make_shared<Obstacle>(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 40, 367),
			40,
			220
			);

		gameObjects.push_back(obstacleTop);
		gameObjects.push_back(obstacleBottom);
		gameObjects.push_back(obstacleLeft);
		gameObjects.push_back(obstacleRight);
		gameObjects.push_back(obstacleTopLeft);
		gameObjects.push_back(obstacleBottomLeft);
		gameObjects.push_back(obstacleTopRight);
		gameObjects.push_back(obstacleBottomRight);
	}

	std::vector<std::shared_ptr<GameObject>> GameState::getGameObjects() const
	{
		return gameObjects;
	}

	void GameState::handleInput()
	{
		sf::Event event;

		while (GameData::getInstance()->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				GameData::getInstance()->window.close();

			if (sf::Event::KeyPressed == event.type || sf::Event::KeyReleased == event.type)
				GameData::getInstance()->inputs.update();
		}
	}

	void GameState::update(float dt)
	{
		sortAllGameObjects();

		for(auto& gameObject : gameObjects)
			gameObject->update(dt);

		GameData::getInstance()->worldManager.update(dt);
	}

	void GameState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(background);

		for (auto& object : gameObjects)
			object->draw();

		GameData::getInstance()->worldManager.getWorld()->DrawDebugData();
		GameData::getInstance()->window.display();
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
