#include "ScorePrinter.hpp"

namespace Football
{
	ScorePrinter::ScorePrinter(int a, int b)
	{
		scoreText = std::make_shared<sf::Text>();
		stringStream = std::make_unique<std::stringstream>();

		scoreText->setFont(GameData::getInstance()->assets.GetFont("RobotoMedium"));
		scoreText->setCharacterSize(18);
		scoreText->setFillColor(sf::Color::White);

		update(a, b);
	}

	ScorePrinter::~ScorePrinter()
	{
	}

	void ScorePrinter::update(int a, int b)
	{
		stringStream->str(std::string());
		*stringStream << a << " : " << b;

		scoreText->setString(stringStream->str());
		scoreText->setPosition( 10, 0);
	}

	void ScorePrinter::draw()
	{
		GameData::getInstance()->window.draw(*scoreText.get());
	}

}
