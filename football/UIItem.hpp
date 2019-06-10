#pragma once
#include "GameData.hpp"
#include <sstream>

namespace Football
{
	class UIItem
	{
	protected:
		bool clickable;
		std::unique_ptr<sf::Text> text;
		std::unique_ptr<sf::RectangleShape> background;
		sf::Vector2f centerAnchor;
	public:
		UIItem(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned int fontSize = 20, sf::Color color = sf::Color::Black, std::string fontName = "RobotoBlack", float bgPadding = 0, sf::Color bgColor = sf::Color::White);
		~UIItem();
		virtual void update();
		virtual void draw() final;
		virtual void onClick();

		virtual void setText(std::string textToDisplay);
	};

}
