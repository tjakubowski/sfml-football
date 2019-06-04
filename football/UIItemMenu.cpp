#include "UIItemMenu.hpp"
#include "MenuState.hpp"

namespace Football
{
	UIItemMenu::UIItemMenu(sf::Vector2f centerAnchor, std::string textToDisplay, float bgPadding, unsigned fontSize, sf::Color color, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, bgPadding, fontSize, color, bgColor)
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
