#include "ScoresState.hpp"
#include "DEFINITIONS.hpp"
#include "UIItemMenu.hpp"
#include "UIItemScores.hpp"

namespace Football
{

	ScoresState::ScoresState()
	{
	}

	ScoresState::~ScoresState()
	{
	}

	void ScoresState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Menu background", TEX_MENU_BG);

		GameData::getInstance()->assets.LoadFont("RobotoMedium", FONT_ROBOTO_MEDIUM);
		GameData::getInstance()->assets.LoadFont("RobotoBlack", FONT_ROBOTO_BLACK);

		_background.setTexture(GameData::getInstance()->assets.GetTexture("Menu background"));

		;
		initUI();
	}

	void ScoresState::initUI()
	{
		const auto windowCenter = GameData::getInstance()->window.getSize().x / 2.f;
		uiManager = std::make_unique<UIContainer>();

		float positionY = 30;
		const float offsetY = 100;

		for(auto& score : GameData::getInstance()->scores.getScores())
		{
			uiManager->addUIItem(std::make_shared<UIItemScores>(
				sf::Vector2f(windowCenter, positionY),
				"Menu",
				20.f
				));

			positionY += offsetY;
		}

		uiManager->addUIItem(std::make_shared<UIItemMenu>(
			sf::Vector2f(windowCenter, positionY),
			"Menu",
			20.f
			));
	}

	void ScoresState::update(float dt)
	{
		uiManager->update();
	}

	void ScoresState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(_background);

		uiManager->draw();

		GameData::getInstance()->window.display();
	}
}
