#include "MatchTimer.hpp"
#include "GameState.hpp"

namespace Football
{
	MatchTimer::MatchTimer(sf::Vector2f centerAnchor, std::string textToDisplay, unsigned fontSize, sf::Color color, std::string fontName, float bgPadding, sf::Color bgColor) : UIItem(centerAnchor, textToDisplay, fontSize, color, fontName, bgPadding, bgColor)
	{
		clickable = false;

		matchDuration = 60;
		timeLeft = matchDuration;
		matchStartTime = static_cast<int>(clock.getElapsedTime().asSeconds());
	}


	MatchTimer::~MatchTimer()
	{
	}

	void MatchTimer::update()
	{
		UIItem::update();

		stringStream->str(std::string());

		timeLeft = matchDuration - static_cast<int>(clock.getElapsedTime().asSeconds()) - matchStartTime;
		const int minutesLeft = timeLeft / 60;
		const int secondsLeft = timeLeft % 60;

		*stringStream << std::setfill('0') << std::setw(2) << minutesLeft << ":" << std::setfill('0') << std::setw(2) << secondsLeft;

		text->setString(stringStream->str());
		text->setPosition(centerAnchor - sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height) / 2.f);

		if (timeLeft == 0)
		{
			const auto gameState = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get());
			gameState->endGame();
		}
	}

	void MatchTimer::stop()
	{
		matchDuration = timeLeft;
	}

	void MatchTimer::start()
	{
		clock.restart();
	}
}
