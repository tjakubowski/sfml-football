#include "Goal.hpp"

namespace Football
{
	Goal::Goal(sf::Vector2f position, float width, float height) : GameObject(position, b2_staticBody)
	{
		tag = "goal";

		b2PolygonShape shape;
		shape.SetAsBox(width / (2.f * PHYSICS_SCALE), height / (2.f * PHYSICS_SCALE));

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.isSensor = true;
		body->CreateFixture(&fixtureDef);

		body->SetTransform(
			b2Vec2(
			(position.x + (width / 2.f)) / PHYSICS_SCALE,
				(position.y + (height / 2.f)) / PHYSICS_SCALE
			),
			body->GetAngle());
	}

	Goal::~Goal()
	{
	}

	void Goal::setTeam(Team* team)
	{
		this->team = team;
	}

	void Goal::update(float dt)
	{
	}

	void Goal::draw()
	{
	}

	void Goal::onCollision(GameObject* collisionObject)
	{
	}
}
