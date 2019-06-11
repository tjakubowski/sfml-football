#include "State.hpp"
#include "GameData.hpp"

namespace Football
{
	void State::handleInput()
	{
		sf::Event event;

		GameData::getInstance()->inputs.updateEvents();

		while (GameData::getInstance()->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				GameData::getInstance()->window.close();

			if (sf::Event::KeyPressed == event.type)
				GameData::getInstance()->inputs.addEvent(event.key.code);

			if (sf::Event::KeyReleased == event.type)
				GameData::getInstance()->inputs.removeEvent(event.key.code);

			if (sf::Event::MouseButtonPressed == event.type)
				GameData::getInstance()->inputs.addEvent(event.mouseButton.button);

			if (sf::Event::MouseButtonReleased == event.type)
				GameData::getInstance()->inputs.removeEvent(event.mouseButton.button);
		}
	}
}
