#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Football
{

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Football pitch", TEX_FOOTBALL_PITCH);

		_background.setTexture(this->_data->assets.GetTexture("Football pitch"));
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

	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}




}
