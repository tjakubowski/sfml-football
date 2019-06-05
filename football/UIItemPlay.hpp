#pragma once
#include "UIItem.hpp"

namespace Football
{
	class UIItemPlay : public UIItem
	{
	private:
		bool multiplayer;
	public:
		UIItemPlay(const bool multiplayer, sf::Vector2f centerAnchor, std::string textToDisplay, float bgPadding = 0, unsigned fontSize = 20, sf::Color color = sf::Color::Black, sf::Color bgColor = sf::Color::White);
		~UIItemPlay();
		void onClick() override;
	};
}
