#include "Goal.hpp"
#include "GameState.hpp"

namespace Football
{

	Goal::Goal(sf::Vector2f position, float width, float height, std::shared_ptr<Team> team) : GameObject(position, b2_staticBody), team(team), width(width), height(height)
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

	void Goal::update(float dt)
	{
	}

	void Goal::draw()
	{
	}

	void Goal::onCollision(GameObject* collisionObject)
	{
		if(collisionObject->getTag() == "ball")
		{
			const auto gameState = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get());
			gameState->scoreGoal(team->getSide());
		}
	}

	float Goal::getWidth() const
	{
		return width;
	}

	float Goal::getHeight() const
	{
		return height;
	}
}
