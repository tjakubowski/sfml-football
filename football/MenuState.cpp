#include <sstream>
#include "MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "UIItemPlay.hpp"
#include "UIItemExit.hpp"
#include "UIItemScores.hpp"

namespace Football
{

	MenuState::MenuState()
	{

	}

	void MenuState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Menu background", TEX_MENU_BG);

		GameData::getInstance()->assets.LoadFont("RobotoMedium", FONT_ROBOTO_MEDIUM);
		GameData::getInstance()->assets.LoadFont("RobotoBlack", FONT_ROBOTO_BLACK);

		_background.setTexture(GameData::getInstance()->assets.GetTexture("Menu background"));

		initUI();
	}

	void MenuState::initUI()
	{
		const auto windowCenter = GameData::getInstance()->window.getSize().x / 2.f;
		uiManager = std::make_unique<UIContainer>();

		uiManager->addUIItem(std::make_shared<UIItemPlay>(
			false,
			sf::Vector2f(windowCenter, 200),
			"Graj z komputerem",
			20.f
			));

		uiManager->addUIItem(std::make_shared<UIItemPlay>(
			true,
			sf::Vector2f(windowCenter, 300),
			"Graj z innym graczem",
			20.f
			));

		uiManager->addUIItem(std::make_shared<UIItemScores>(
			sf::Vector2f(windowCenter, 400),
			"Wyniki",
			20.f
			));

		uiManager->addUIItem(std::make_shared<UIItemExit>(
			sf::Vector2f(windowCenter, 500),
			"Wyjdz",
			20.f
			));
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
