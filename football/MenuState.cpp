#include <sstream>
#include "MenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Football
{

	MenuState::MenuState(GameDataRef data) : _data(data)
	{

	}

	void MenuState::init()
	{
		_data->assets.LoadTexture("Menu background", TEX_MENU_BG);

		_background.setTexture(this->_data->assets.GetTexture("Menu background"));
	}

	void MenuState::handleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				_data->window.close();
		}
	}

	void MenuState::update(float dt)
	{

	}

	void MenuState::draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}




}
