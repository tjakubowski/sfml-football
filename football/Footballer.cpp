#include "Footballer.hpp"
#include "GameState.hpp"

namespace Football
{
	Footballer::Footballer(sf::Vector2f position, std::shared_ptr<Team> team) : GameObject(position, b2BodyType::b2_dynamicBody), team(team)
	{
		GameObject::setSpriteTexture("Footballer");
		maxSpeed = 5.0f;
		tag = "footballer";
		nearBallDistance = 150;
		shootDistance = 60;
		shootForce = 10;
		
		b2CircleShape shape;
		shape.m_radius = sprite.getGlobalBounds().width / (2 * PHYSICS_SCALE);
		shape.m_p.Set(0, sprite.getGlobalBounds().height / (2 * PHYSICS_SCALE) - shape.m_radius);

		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.5f;
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
	}

	void Footballer::onCollision(GameObject* collisionObject)
	{
	}

	void Footballer::setGoalPart(int goalPartIndex)
	{
		goalPart = goalPartIndex;
	}

	bool Footballer::canShoot() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();

		return sqrMagnitude(ball->getPosition() - getPosition()) <= shootDistance * shootDistance;
	}

	void Footballer::shoot() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();

		ball->getKickFrom(getPosition(), shootForce);
	}

	bool Footballer::isNearBall() const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();
		return sqrMagnitude(ball->getPosition() - getPosition()) <= nearBallDistance * nearBallDistance;
	}
}
