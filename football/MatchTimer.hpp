#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameState.hpp"
#include <sstream>
#include <iomanip>

namespace Football
{
	class MatchTimer
	{
		sf::Clock clock;
		int timeLeft;
		int matchDuration;
		int matchStartTime;

		std::shared_ptr<sf::Text> scoreText;
		std::unique_ptr<std::stringstream> stringStream;
	public:
		MatchTimer();
		~MatchTimer();
		void update();
		void draw() const;

		void stop();
		void start();
	};
}