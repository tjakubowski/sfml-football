#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{

	GameState::GameState(GameDataRef data) : data(data)
	{

	}

	void GameState::init()
	{
		data->assets.LoadTexture("Football pitch", TEX_FOOTBALL_PITCH);
		data->assets.LoadTexture("Footballer", TEX_FOOTBALLER);
		data->assets.LoadTexture("Player", TEX_PLAYER);

		background.setTexture(this->data->assets.GetTexture("Football pitch"));

		initTeams();
	}

	void GameState::initTeams()
	{
		leftTeam = std::make_unique<Team>("Left Team");
		rightTeam = std::make_unique<Team>("Right Team");

		auto player = std::make_shared<Player>(data, "Player");
		auto aiPlayer = std::make_shared<AIPlayer>(data, "Bot");

		leftTeam->addPlayer(player);
		leftTeam->addPlayer(aiPlayer);

		gameObjects.push_back(player);
		gameObjects.push_back(aiPlayer);
	}

	void GameState::handleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				data->window.close();

			if (sf::Event::KeyPressed == event.type || sf::Event::KeyReleased == event.type)
				data->inputs.update();
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
		data->window.clear();

		data->window.draw(background);

		for (auto& fb : gameObjects)
			fb->draw();

		data->window.display();
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
