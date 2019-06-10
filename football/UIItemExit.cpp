#include "UIItemExit.hpp"

namespace Football
{
	UIItemExit::UIItemExit(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, fontSize, color, fontName, bgPadding, bgColor)
	{
	}

	UIItemExit::~UIItemExit()
	{
	}

	void UIItemExit::onClick()
	{
		GameData::getInstance()->window.close();
	}
}
