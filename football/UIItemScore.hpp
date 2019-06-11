#pragma once
#include "UIItem.hpp"

namespace Football
{
	class UIItemScore : public UIItem
	{
	private:
		std::string timestampToDate(time_t timestamp);
	public:
		UIItemScore(sf::Vector2f centerAnchor, Score score, unsigned int fontSize = 20, sf::Color color = sf::Color::Black, std::string fontName = "RobotoMedium", float bgPadding = 0, sf::Color bgColor = sf::Color::White);
		~UIItemScore();
		void onClick() override;
	};
}
