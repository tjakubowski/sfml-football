#pragma once
#include "UIItem.hpp"
#include <sstream>

namespace Football
{
	class ScorePrinter : public UIItem
	{
	public:
		ScorePrinter(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize = 20, sf::Color color = sf::Color::Black, std::string fontName = "RobotoBlack", float bgPadding = 0, sf::Color bgColor = sf::Color::White);
		~ScorePrinter();
		void update(const int a, const int b) const;
	};
}
