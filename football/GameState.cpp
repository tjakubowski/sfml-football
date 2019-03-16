#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Football pitch", TEX_FOOTBALL_PITCH);
		_data->assets.LoadTexture("Footballer", TEX_FOOTBALLER);
		_data->assets.LoadTexture("Player", TEX_PLAYER);

		_background.setTexture(this->_data->assets.GetTexture("Football pitch"));

		InitTeams();
	}

	void GameState::InitTeams()
	{
		leftTeam = std::make_unique<Team>("Left Team");
		rightTeam = std::make_unique<Team>("Right Team");

		auto player = std::make_unique<Player>(_data, "Player");
		auto aiPlayer = std::make_unique<AIPlayer>(_data, "Footballer");

		leftTeam->AddPlayer(std::move(player));
		leftTeam->AddPlayer(std::move(aiPlayer));
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				_data->window.close();
		}
	}

	void GameState::Update(float dt)
	{
		for(auto& fb : leftTeam->GetFootballers())
			fb->Update(dt);
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		for (auto& fb : leftTeam->GetFootballers())
			fb->Draw();

		_data->window.display();
	}

}
