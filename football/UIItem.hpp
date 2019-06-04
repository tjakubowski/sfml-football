#pragma once
#include "GameData.hpp"
#include <sstream>

namespace Football
{
	class UIItem
	{
	private:
		std::unique_ptr<sf::Text> text;
		std::unique_ptr<sf::RectangleShape> background;
		sf::Vector2f centerAnchor;
	public:
		UIItem(sf::Vector2f centerAnchor, std::string textToDisplay, float bgPadding = 0, unsigned fontSize = 20, sf::Color color = sf::Color::Black, sf::Color bgColor = sf::Color::White);
		~UIItem();
		virtual void update() final;
		virtual void draw() final;
		virtual void onClick();

		virtual void setText(std::string textToDisplay);
	};

}
