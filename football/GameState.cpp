#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::init()
	{
		_data->assets.LoadTexture("Football pitch", TEX_FOOTBALL_PITCH);
		_data->assets.LoadTexture("Footballer", TEX_FOOTBALLER);
		_data->assets.LoadTexture("Player", TEX_PLAYER);

		_background.setTexture(this->_data->assets.GetTexture("Football pitch"));

		initTeams();
	}

	void GameState::initTeams()
	{
		leftTeam = std::make_unique<Team>("Left Team");
		rightTeam = std::make_unique<Team>("Right Team");

		auto player = std::make_shared<Player>(_data, "Player");
		auto aiPlayer = std::make_shared<AIPlayer>(_data, "Footballer");

		leftTeam->addPlayer(player);
		leftTeam->addPlayer(aiPlayer);

		gameObjects.push_back(player);
		gameObjects.push_back(aiPlayer);
	}

	void GameState::handleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				_data->window.close();
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
		_data->window.clear();

		_data->window.draw(_background);

		for (auto& fb : gameObjects)
			fb->draw();

		_data->window.display();
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
