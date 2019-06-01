#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "Goal.hpp"
#include "Ball.hpp"

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
		GameData::getInstance()->assets.LoadTexture("Goal", TEX_GOAL);
		GameData::getInstance()->assets.LoadTexture("Ball", TEX_BALL);

		background.setTexture(GameData::getInstance()->assets.GetTexture("Football pitch"));

		initObjects();
		initTeams();
	}

	void GameState::initObjects()
	{
		auto ball = std::make_shared<Ball>(static_cast<sf::Vector2f>(GameData::getInstance()->window.getSize()) / 2.0f);
		auto goalLeft = std::make_shared<Goal>(sf::Vector2f(10, 220));
		auto goalRight = std::make_shared<Goal>(sf::Vector2f(300, 220));

		gameObjects.push_back(ball);
		gameObjects.push_back(goalLeft);
		gameObjects.push_back(goalRight);
	}

	void GameState::initTeams()
	{
		leftTeam = std::make_unique<Team>("Left Team");
		rightTeam = std::make_unique<Team>("Right Team");

		auto player = std::make_shared<Player>(sf::Vector2f(80, 220), "Player");
		auto aiPlayer = std::make_shared<AIPlayer>(sf::Vector2f(50, 220), "Bot");

		leftTeam->addPlayer(player);
		leftTeam->addPlayer(aiPlayer);

		gameObjects.push_back(player);
		gameObjects.push_back(aiPlayer);
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

		checkCollisions();
	}

	void GameState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(background);

		for (auto& fb : gameObjects)
			fb->draw();

		GameData::getInstance()->window.display();
	}

	void GameState::checkCollisions()
	{
		for (unsigned int i = 0; i < gameObjects.size() - 1; i++)
			for (unsigned int j = i + 1; j < gameObjects.size(); j++)
				gameObjects[i]->getCollider()->checkCollision(gameObjects[j]->getCollider());
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
