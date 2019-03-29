#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Football
{
	class MenuState : public State
	{
	public:
		MenuState();

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}
