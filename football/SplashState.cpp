#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>
#include "GameState.hpp"

namespace Football
{
	
	SplashState::SplashState(GameDataRef data) : _data(data)
	{
		
	}

	void SplashState::init()
	{
		_data->assets.LoadTexture("Splash background", TEX_SPLASH_SCREEN_BG);

		_background.setTexture(this->_data->assets.GetTexture( "Splash background" ));
	}

	void SplashState::handleInput()
	{
		sf::Event event;

		while(_data->window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				_data->window.close();
		}
	}

	void SplashState::update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME )
		{
			_data->machine.AddState(StateRef(new GameState(_data)));
		}
	}

	void SplashState::draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}




}
