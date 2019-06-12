#include "Goalkeeper.hpp"
#include "GameState.hpp"

namespace Football
{
	Goalkeeper::Goalkeeper(std::shared_ptr<Team> team) : Bot(sf::Vector2f(0, 0), team)
	{
		tag = "goalkeeper";

		const auto offset = sf::Vector2f((team->getGoal()->getWidth() + GameObject::getWidth()) / 2, 0);
		startPosition = team->getGoal()->getPosition() + offset * (team->getSide() == Team::Left ? 1.f : -1.f);
		maxGoalDistanceX = 100.f;
		maxGoalDistanceY = 100.f;

		body->SetTransform(b2Vec2(
			startPosition.x / PHYSICS_SCALE,
			startPosition.y / PHYSICS_SCALE
		), body->GetAngle());

		body->GetFixtureList()->SetDensity(7.f);
	}

	Goalkeeper::~Goalkeeper()
	{
	}

	void Goalkeeper::update(float dt)
	{
		Bot::update(dt);

		moveTowards(calculateGoalkeeperPosition());
	}

	sf::Vector2f Goalkeeper::calculateGoalkeeperPosition() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();
		const auto windowSize = GameData::getInstance()->window.getSize();

		auto normalizedDirection = normalize(ball->getPosition() - getPosition());
		const auto ratioX = team->getSide() == Team::Left
			? ball->getPosition().x / windowSize.x
			: (windowSize.x - ball->getPosition().x) / windowSize.x;

		normalizedDirection.x *= maxGoalDistanceX * ratioX;
		normalizedDirection.y *= maxGoalDistanceY;

		return startPosition + normalizedDirection;
	}
	
}
