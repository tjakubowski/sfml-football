#include <sstream>
#include "MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "UIItemPlay.hpp"
#include "UIItemMenu.hpp"
#include "UIItemExit.hpp"

namespace Football
{

	MenuState::MenuState()
	{

	}

	void MenuState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Menu background", TEX_MENU_BG);

		GameData::getInstance()->assets.LoadFont("RobotoMedium", FONT_ROBOTO_MEDIUM);

		_background.setTexture(GameData::getInstance()->assets.GetTexture("Menu background"));

		initUI();
	}

	void MenuState::initUI()
	{
		const auto windowCenter = GameData::getInstance()->window.getSize().x / 2.f;
		uiManager = std::make_unique<UIManager>();

		uiManager->addUIItem(std::make_shared<UIItemPlay>(
			sf::Vector2f(windowCenter, 200),
			"Graj",
			20.f
			));

		uiManager->addUIItem(std::make_shared<UIItemExit>(
			sf::Vector2f(windowCenter, 350),
			"Wyjdz",
			20.f
			));
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
		uiManager->update();
	}

	void MenuState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(_background);

		uiManager->draw();

		GameData::getInstance()->window.display();
	}




}
