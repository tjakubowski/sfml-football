#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "UIContainer.hpp"

namespace Football
{
	class ScoresState : public State
	{
	private:
		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		std::unique_ptr<UIContainer> uiManager;

		void initUI();
	public:
		ScoresState();
		~ScoresState();

		void init() override;
		void update(float dt) override;
		void draw(float dt) override;
	};

}
