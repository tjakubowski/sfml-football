#pragma once
#include "UIItem.hpp"

namespace Football
{
	class UIItemScores : public UIItem
	{
	public:
		UIItemScores(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned int fontSize = 20, sf::Color color = sf::Color::Black, std::string fontName = "RobotoMedium", float bgPadding = 15, sf::Color bgColor = sf::Color::White);
		~UIItemScores();
		void onClick() override;
	};
}

