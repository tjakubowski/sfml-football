#include "GameState.hpp"
#include "DEFINITIONS.hpp"

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

		background.setTexture(GameData::getInstance()->assets.GetTexture("Football pitch"));

		initTeams();
	}

	void GameState::initTeams()
	{
		leftTeam = std::make_unique<Team>("Left Team");
		rightTeam = std::make_unique<Team>("Right Team");

		auto player = std::make_shared<Player>("Player");
		auto aiPlayer = std::make_shared<AIPlayer>("Bot");

		leftTeam->addPlayer(player);
		leftTeam->addPlayer(aiPlayer);

		gameObjects.push_back(player);
		gameObjects.push_back(aiPlayer);
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

		for(auto& fb : leftTeam->getFootballers())
			fb->update(dt);
	}

	void GameState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(background);

		for (auto& fb : gameObjects)
			fb->draw();

		GameData::getInstance()->window.display();
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
