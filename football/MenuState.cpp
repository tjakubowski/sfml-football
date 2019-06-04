#include <sstream>
#include "MenuState.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{

	MenuState::MenuState()
	{

	}

	void MenuState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Menu background", TEX_MENU_BG);

		_background.setTexture(GameData::getInstance()->assets.GetTexture("Menu background"));
	}

	void MenuState::handleInput()
	{
		sf::Event event;

		while (GameData::getInstance()->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				GameData::getInstance()->window.close();
		}
	}

	void MenuState::update(float dt)
	{
	}

	void MenuState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(_background);

		GameData::getInstance()->window.display();
	}




}
