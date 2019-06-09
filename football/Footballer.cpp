#include "Footballer.hpp"
#include "GameState.hpp"
#include "FootballerRaycastCallback.hpp"

namespace Football
{
	Footballer::Footballer(sf::Vector2f position, std::shared_ptr<Team> team) : GameObject(position, b2_dynamicBody), team(team)
	{
		if (team->getSide() == Team::Side::Left)
			animation = std::make_unique<Animation>("footballer_blue", &sprite, 3, .1f);
		else
			animation = std::make_unique<Animation>("footballer_red", &sprite, 3, .1f);

		maxSpeed = 6.0f;
		tag = "footballer";
		nearBallDistance = 70;
		shootZoneDistance = 250;
		ballShootDistance = 50;
		shootForce = 10;
		
		b2CircleShape shape;
		shape.m_radius = sprite.getGlobalBounds().width / (2 * PHYSICS_SCALE);
		shape.m_p.Set(0, sprite.getGlobalBounds().height / (2 * PHYSICS_SCALE) - shape.m_radius);

		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.9f;
		fixtureDef.friction = 0.2f;
		fixtureDef.shape = &shape;
		body->CreateFixture(&fixtureDef);
		body->SetLinearDamping(maxSpeed);
	}

	Footballer::~Footballer()
	{
		
	}

	void Footballer::update(float dt)
	{
		animation->update(dt);
	}

	void Footballer::onCollision(GameObject* collisionObject)
	{
	}

	void Footballer::setGoalPart(int goalPartIndex)
	{
		goalPart = goalPartIndex;
	}

	float Footballer::getBallDistanceSqr() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();

		FootballerRaycastCallback cb;
		b2Vec2 myPos(getPosition().x / PHYSICS_SCALE, getPosition().y / PHYSICS_SCALE);
		b2Vec2 ballPos(ball->getPosition().x / PHYSICS_SCALE, ball->getPosition().y / PHYSICS_SCALE);

		dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())
			->getWorld()->RayCast(&cb, myPos, ballPos);

		return sqrMagnitude(ball->getPosition() - getPosition());
	}

	bool Footballer::isCloseToBall() const
	{
		return getBallDistanceSqr() <= ballShootDistance * ballShootDistance;
	}

	bool Footballer::isInShootDistance() const
	{
		return sqrMagnitude(team->getOpponentGoal()->getPosition() - getPosition()) <= shootZoneDistance * shootZoneDistance;
	}

	void Footballer::shoot() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();

		ball->getKickFrom(getPosition(), shootForce);
	}

	bool Footballer::isNearBall() const
	{
		return getBallDistanceSqr() <= nearBallDistance * nearBallDistance;
	}
}
