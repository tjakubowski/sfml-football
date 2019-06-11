#include "UIItemScore.hpp"

namespace Football
{
	UIItemScore::UIItemScore(sf::Vector2f centerAnchor, Score score, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, "", fontSize, color, fontName, bgPadding, bgColor)
	{
		clickable = false;

		stringStream->str(std::string());
		*stringStream << score.leftPoints << " : " << score.rightPoints << "\t" << timestampToDate(score.timestamp);

		text->setString(stringStream->str());

		text->setPosition(centerAnchor - sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height) / 2.f);
	}

	UIItemScore::~UIItemScore()
	{
	}

	std::string UIItemScore::timestampToDate(const time_t timestamp)
	{
		char buffer[30];
		struct tm* dt = localtime(&timestamp);
		strftime(buffer, sizeof(buffer), "%H:%M, %d.%m.%y", dt);
		return std::string(buffer);
	}

	void UIItemScore::onClick()
	{

	}
}
