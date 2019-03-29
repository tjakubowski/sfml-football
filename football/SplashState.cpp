#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>
#include "GameState.hpp"

namespace Football
{
	
	SplashState::SplashState()
	{
	}

	void SplashState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Splash background", TEX_SPLASH_SCREEN_BG);

		_background.setTexture(GameData::getInstance()->assets.GetTexture( "Splash background" ));
	}

	void SplashState::handleInput()
	{
		sf::Event event;

		while(GameData::getInstance()->window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				GameData::getInstance()->window.close();
		}
	}

	void SplashState::update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			GameData::getInstance()->machine.AddState(StateRef(new GameState()));
		}
	}

	void SplashState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(_background);

		GameData::getInstance()->window.display();
	}




}
