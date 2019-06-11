#include "ScorePrinter.hpp"
#include "GameState.hpp"

namespace Football
{
	ScorePrinter::ScorePrinter(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, fontSize, color, fontName, bgPadding, bgColor)
	{
		clickable = false;
	}

	ScorePrinter::~ScorePrinter()
	{
	}

	void ScorePrinter::update(int a, int b) const
	{
		stringStream->str(std::string());
		*stringStream << a << " : " << b;

		text->setString(stringStream->str());

		text->setPosition(centerAnchor - sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height) / 2.f);
	}
}
