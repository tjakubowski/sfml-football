#include "Bot.hpp"

namespace Football
{

	Bot::Bot(sf::Vector2f position) : Footballer(position)
	{
		moveTowardsStopDistance = 3.0f;
	}

	Bot::~Bot()
	{
	}

	void Bot::update(float dt)
	{
	}

	void Bot::moveTowards(sf::Vector2f targetPosition) const
	{
		auto myPosition = sf::Vector2f(body->GetPosition().x * PHYSICS_SCALE, body->GetPosition().y * PHYSICS_SCALE);
		auto directionVector = targetPosition - myPosition;

		// Stop when bot is close enough to the target
		if (sqrMagnitude(directionVector) < moveTowardsStopDistance * moveTowardsStopDistance)
			return;

		auto force = b2Vec2(directionVector.x, directionVector.y);
		force.Normalize();

		body->ApplyLinearImpulseToCenter(b2Vec2(force), true);
	}

	void Bot::moveTowards(const float x, const float y) const
	{
		moveTowards(sf::Vector2f(x, y));
	}
	
}
