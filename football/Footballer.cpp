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

		damping = 6.0f;
		tag = "footballer";
		nearBallDistance = 70;
		shootZoneDistance = 250;
		ballShootDistance = 50;
		shootForce = 10;
		shootWaitTime = .6f;
		waitToShootTime = 0;
		
		b2CircleShape shape;
		shape.m_radius = sprite.getGlobalBounds().width / (2 * PHYSICS_SCALE);
		shape.m_p.Set(0, sprite.getGlobalBounds().height / (2 * PHYSICS_SCALE) - shape.m_radius);

		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.9f;
		fixtureDef.friction = 0.2f;
		fixtureDef.shape = &shape;
		body->CreateFixture(&fixtureDef);
		body->SetLinearDamping(damping);
	}

	Footballer::~Footballer()
	{
		
	}

	void Footballer::update(float dt)
	{
		waitForShoot(dt);

		if (body->GetLinearVelocity().Length() > 1.f)
			animation->update(dt);
		else
			animation->reset();
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

	void Footballer::waitForShoot(float dt)
	{
		waitToShootTime -= dt;
	}

	void Footballer::shoot(float force)
	{
		waitToShootTime = shootWaitTime;

		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();
		ball->getKickFrom(getPosition(), shootForce * force);
	}

	bool Footballer::isPreparedToShoot() const
	{
		return waitToShootTime <= 0;
	}

	bool Footballer::isNearBall() const
	{
		return getBallDistanceSqr() <= nearBallDistance * nearBallDistance;
	}
}
