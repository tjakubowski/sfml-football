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

		auto player = std::make_shared<Player>(_data, "Player");
		auto aiPlayer = std::make_shared<AIPlayer>(_data, "Footballer");

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

		for (auto& fb : GetAllFootballersSorted())
			fb->Draw();

		_data->window.display();
	}

	std::vector<std::shared_ptr<Footballer>> GameState::GetAllFootballers() const
	{
		std::vector<std::shared_ptr<Footballer>> allFootballers;

		allFootballers.reserve(leftTeam->GetFootballers().size() + rightTeam->GetFootballers().size());
		allFootballers.insert(allFootballers.end(), leftTeam->GetFootballers().begin(), leftTeam->GetFootballers().end());
		allFootballers.insert(allFootballers.end(), rightTeam->GetFootballers().begin(), rightTeam->GetFootballers().end());

		return allFootballers;
	}

	std::vector<std::shared_ptr<Footballer>> GameState::GetAllFootballersSorted() const
	{
		auto footballersSorted = GetAllFootballers();

		std::sort(footballersSorted.begin(), footballersSorted.end());

		return footballersSorted;
	}

}
