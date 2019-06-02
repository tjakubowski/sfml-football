#include "ScoreUI.hpp"

namespace Football
{
	ScoreUI::ScoreUI(sf::Vector2f position, std::shared_ptr<Team> leftTeam, std::shared_ptr<Team> rightTeam) : GameObject(position), leftTeam(leftTeam), rightTeam(rightTeam)
	{
		text = sf::Text("0 : 0", GameData::getInstance()->assets.GetFont("RobotoMedium"));
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
		text.setPosition(position);

	}

	ScoreUI::~ScoreUI()
	{
	}

	void ScoreUI::draw()
	{
		GameData::getInstance()->window.draw(text);
	}

	void ScoreUI::update(float dt)
	{
		ss.str(std::string());
		ss << leftTeam->getPoints() << " : " << rightTeam->getPoints();
		text.setString(ss.str());
	}

	void ScoreUI::onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint)
	{
	}
}
