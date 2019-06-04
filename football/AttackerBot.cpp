#include "AttackerBot.hpp"
#include "GameState.hpp"

namespace Football
{
	bool AttackerBot::isTeammateNearBall()
	{
		for(std::shared_ptr<Footballer> &footballer : team->getFootballers())
		{
			if (footballer.get() == this || footballer->getTag() == "goalkeeper")
				continue;

			if (footballer->isNearBall())
				return true;
		}

		return false;
	}

	sf::Vector2f AttackerBot::calculateGoalPosition() const
	{
		const std::shared_ptr<Goal> opponentGoal = (team->getSide() == Team::Side::Left
			? dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getTeam(Team::Side::Right)
			: dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getTeam(Team::Side::Left)
			)->getGoal();

		const auto goalHeight = opponentGoal->getHeight();
		const auto goalSegmentHeight = goalHeight / team->getFootballers().size();
		const auto goalTopPositionY = opponentGoal->getPosition().y - goalHeight / 2;
		const auto goalPositionY = goalTopPositionY + goalSegmentHeight * static_cast<float>(goalPart) + goalSegmentHeight / 2;
		
		return sf::Vector2f(opponentGoal->getPosition().x, goalPositionY);
	}

	sf::Vector2f AttackerBot::calculatePositionNearBall() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();

		return getPosition() + (ball->getPosition() - getPosition()) / 2.f;
	}

	sf::Vector2f AttackerBot::calculateShootPosition() const
	{
		const auto goalPosition = calculateGoalPosition();
		const auto ballPosition = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall()->getPosition();
		const auto extensionVector = normalize(ballPosition - goalPosition) * 20.f;

		return ballPosition + extensionVector;
	}

	AttackerBot::AttackerBot(sf::Vector2f position, std::shared_ptr<Team> team) : Bot(position, team)
	{
	}

	AttackerBot::~AttackerBot()
	{
	}

	void AttackerBot::update(float dt)
	{
		if(isTeammateNearBall())
		{
			moveTowards(calculatePositionNearBall());
		}
		else
		{
			moveTowards(calculateShootPosition());

			if (canShoot())
				shoot();
		}
	}
}
