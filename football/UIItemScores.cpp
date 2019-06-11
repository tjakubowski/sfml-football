#include "UIItemScores.hpp"
#include "ScoresState.hpp"

namespace Football
{
	UIItemScores::UIItemScores(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, fontSize, color, fontName, bgPadding, bgColor)
	{
	}

	UIItemScores::~UIItemScores()
	{
	}

	void UIItemScores::onClick()
	{
		GameData::getInstance()->machine.AddState(StateRef(new ScoresState()));
	}
}
