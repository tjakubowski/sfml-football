#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Football
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void init();

		void handleInput();
		void update( float dt );
		void draw( float dt );

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}
