#include "MatchTimer.hpp"

namespace Football
{
	MatchTimer::MatchTimer()
	{
		scoreText = std::make_shared<sf::Text>();
		stringStream = std::make_unique<std::stringstream>();

		scoreText->setFont(GameData::getInstance()->assets.GetFont("RobotoMedium"));
		scoreText->setCharacterSize(18);
		scoreText->setFillColor(sf::Color::White);

		matchDuration = 2;
		matchStartTime = static_cast<int>(clock.getElapsedTime().asSeconds());
	}


	MatchTimer::~MatchTimer()
	{
	}

	void MatchTimer::update() const
	{
		stringStream->str(std::string());

		const int timeLeft = matchDuration - static_cast<int>(clock.getElapsedTime().asSeconds()) - matchStartTime;
		const int minutesLeft = timeLeft / 60;
		const int secondsLeft = timeLeft % 60;

		*stringStream << std::setfill('0') << std::setw(2) << minutesLeft << ":" << std::setfill('0') << std::setw(2) << secondsLeft;

		scoreText->setString(stringStream->str());
		scoreText->setPosition(GameData::getInstance()->window.getSize().x - scoreText->getGlobalBounds().width - 10, 0);

		if (timeLeft == 0)
		{
			const auto gameState = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get());
			gameState->endGame();
		}
	}

	void MatchTimer::draw() const
	{
		GameData::getInstance()->window.draw(*scoreText.get());
	}
}
