#include "Goalkeeper.hpp"

namespace Football
{
	Goalkeeper::Goalkeeper(std::shared_ptr<Goal> goal, Side side) : Bot(sf::Vector2f(0, 0))
	{
		const auto offset = sf::Vector2f((goal->getWidth() + getWidth()) / 2, 0);
		startPosition = goal->getPosition() + offset * (side == Left ? 1.f : -1.f);

		body->SetTransform(b2Vec2(
			startPosition.x / PHYSICS_SCALE,
			startPosition.y / PHYSICS_SCALE
		), body->GetAngle());
	}

	Goalkeeper::~Goalkeeper()
	{
	}

	sf::Vector2f Goalkeeper::calculateGoalkeeperPosition()
	{
		return sf::Vector2f(0, 0);
	}
	
}
