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

		player = new Player(_data);
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
		player->Update( dt );
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);
		player->Draw();

		_data->window.display();
	}

}
