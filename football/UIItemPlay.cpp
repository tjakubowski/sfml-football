#include "UIItemPlay.hpp"
#include "GameState.hpp"

namespace Football
{
	UIItemPlay::UIItemPlay(sf::Vector2f centerAnchor, std::string textToDisplay, float bgPadding, unsigned fontSize, sf::Color color, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, bgPadding, fontSize, color, bgColor)
	{
	}

	UIItemPlay::~UIItemPlay()
	{
	}

	void UIItemPlay::onClick()
	{
		GameData::getInstance()->machine.AddState(StateRef(new GameState()));
	}
}
