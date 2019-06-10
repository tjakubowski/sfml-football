#pragma once
#include "UIItem.hpp"

namespace Football
{
	class UIItemExit : public UIItem
	{
	public:
		UIItemExit(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned int fontSize = 20, sf::Color color = sf::Color::Black, std::string fontName = "RobotoMedium", float bgPadding = 15, sf::Color bgColor = sf::Color::White);
		~UIItemExit();
		void onClick() override;
	};
}
