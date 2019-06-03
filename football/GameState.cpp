#include "GameState.hpp"
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
	}

	void GameState::initPlayers()
	{
		const auto player = std::make_shared<Player>(sf::Vector2f(50, 50));
		gameObjects.push_back(player);
	}

	void GameState::initObjects()
	{
		const auto ball = std::make_shared<Ball>(sf::Vector2f(300, 300));
		gameObjects.push_back(ball);
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
