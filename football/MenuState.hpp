#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "UIContainer.hpp"

namespace Football
{
	class MenuState : public State
	{
	private:
		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		std::unique_ptr<UIContainer> uiManager;

		void initUI();

	public:
		MenuState();

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	};
}
