#include "Goalkeeper.hpp"

namespace Football
{
	Goalkeeper::Goalkeeper(std::shared_ptr<Goal> goal, Side side) : Bot(sf::Vector2f(0, 0)), side(side)
	{
		const auto offset = sf::Vector2f((goal->getWidth() + getWidth()) / 2, 0);
		startPosition = goal->getPosition() + offset * (side == Left ? 1.f : -1.f);
		maxGoalDistanceX = 100.f;
		maxGoalDistanceY = 100.f;

		body->SetTransform(b2Vec2(
			startPosition.x / PHYSICS_SCALE,
			startPosition.y / PHYSICS_SCALE
		), body->GetAngle());
	}

	Goalkeeper::~Goalkeeper()
	{
	}

	void Goalkeeper::update(float dt)
	{
		moveTowards(calculateGoalkeeperPosition());
	}

	sf::Vector2f Goalkeeper::calculateGoalkeeperPosition()
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();
		const auto windowSize = GameData::getInstance()->window.getSize();

		auto normalizedDirection = normalize(ball->getPosition() - getPosition());
		const auto ratioX = side == Left
			? ball->getPosition().x / windowSize.x
			: (windowSize.x - ball->getPosition().x) / windowSize.x;

		normalizedDirection.x *= maxGoalDistanceX * ratioX;
		normalizedDirection.y *= maxGoalDistanceY;

		return startPosition + normalizedDirection;
	}
	
}
