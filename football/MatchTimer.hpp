#pragma once
#include <SFML/System/Clock.hpp>
#include "UIItem.hpp"
#include <sstream>
#include <iomanip>

namespace Football
{
	class MatchTimer : public UIItem
	{
		sf::Clock clock;
		int timeLeft;
		int matchDuration;
		int matchStartTime;

		std::unique_ptr<std::stringstream> stringStream;
	public:
		MatchTimer(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize = 20, sf::Color color = sf::Color::Black, std::string fontName = "RobotoBlack", float bgPadding = 0, sf::Color bgColor = sf::Color::White);
		~MatchTimer();
		void update() override;

		void stop();
		void start();
	};
}
