#include "UIItemMenu.hpp"
#include "MenuState.hpp"

namespace Football
{
	UIItemMenu::UIItemMenu(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, fontSize, color, fontName, bgPadding, bgColor)
	{
	}

	UIItemMenu::~UIItemMenu()
	{
	}

	void UIItemMenu::onClick()
	{
		GameData::getInstance()->machine.AddState(StateRef(new MenuState()));
	}
}
