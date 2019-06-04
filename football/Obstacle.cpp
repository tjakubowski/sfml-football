#include "Obstacle.hpp"

namespace Football
{

	Obstacle::Obstacle(sf::Vector2f position, float width, float height, float angleDegrees) : GameObject(position, b2_staticBody), width(width), height(height)
	{
		tag = "obstacle";

		b2PolygonShape shape;
		shape.SetAsBox(width / (2.f * PHYSICS_SCALE), height / (2.f * PHYSICS_SCALE));

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		body->CreateFixture(&fixtureDef);

		body->SetTransform(
			b2Vec2(
			(position.x + (width / 2.f)) / PHYSICS_SCALE,
				(position.y + (height / 2.f)) / PHYSICS_SCALE
			),
			angleDegrees * (3.14 / 180.f));
	}


	Obstacle::~Obstacle()
	{
	}

	void Obstacle::update(float dt)
	{
	}

	void Obstacle::onCollision(GameObject* collisionObject)
	{
	}

	float Obstacle::getWidth() const
	{
		return width;
	}

	float Obstacle::getHeight() const
	{
		return height;
	}

	void Obstacle::setSpriteTexture(std::string textureName)
	{

	}
	
}
