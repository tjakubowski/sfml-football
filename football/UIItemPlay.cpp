#include "UIItemPlay.hpp"
#include "GameState.hpp"

namespace Football
{
	UIItemPlay::UIItemPlay(const bool multiplayer, sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, fontSize, color, fontName, bgPadding, bgColor), multiplayer(multiplayer)
	{
	}

	UIItemPlay::~UIItemPlay()
	{
	}

	void UIItemPlay::onClick()
	{
		GameData::getInstance()->machine.AddState(StateRef(new GameState(multiplayer)));
	}
}
