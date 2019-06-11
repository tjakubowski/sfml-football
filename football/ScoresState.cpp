#include "ScoresState.hpp"
#include "DEFINITIONS.hpp"
#include "UIItemMenu.hpp"
#include "UIItemScore.hpp"

namespace Football
{

	ScoresState::ScoresState()
	{
		maxScoresDisplay = 10;
		positionY = 100;
		offsetY = 50;
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

		int maxScoresDisplay = this->maxScoresDisplay;
		float positionY = this->positionY;
		const float offsetY = this->offsetY;

		auto scores = GameData::getInstance()->scores.getScores();
		std::reverse(scores.begin(), scores.end());

		for(auto& score : scores)
		{
			if (maxScoresDisplay == 0)
				break;

			uiManager->addUIItem(std::make_shared<UIItemScore>(
				sf::Vector2f(windowCenter, positionY),
				score,
				20.f,
				sf::Color::White
				));

			positionY += offsetY;
			maxScoresDisplay--;
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
