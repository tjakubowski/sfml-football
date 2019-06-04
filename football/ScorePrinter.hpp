#pragma once
#include <SFML/Graphics/Text.hpp>
#include "GameState.hpp"
#include <sstream>

namespace Football
{
	class ScorePrinter
	{
		std::shared_ptr<sf::Text> scoreText;
		std::unique_ptr<std::stringstream> stringStream;
	public:
		ScorePrinter(const int a, const int b);
		~ScorePrinter();
		void update(const int a, const int b);
		void draw();
	};
}
