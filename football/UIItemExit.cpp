#include "UIItemExit.hpp"

namespace Football
{
	UIItemExit::UIItemExit(sf::Vector2f centerAnchor, std::string textToDisplay, float bgPadding, unsigned fontSize, sf::Color color, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, bgPadding, fontSize, color, bgColor)
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
