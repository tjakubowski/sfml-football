#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Football
{
	class SplashState : public State
	{
	public:
		SplashState();

		void init();

		void handleInput();
		void update( float dt );
		void draw( float dt );

	private:
		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}
