#include "Ball.hpp"

namespace Football
{
	Ball::Ball(sf::Vector2f position) : GameObject(position, b2BodyType::b2_dynamicBody)
	{
		tag = "ball";

		GameObject::setSpriteTexture("Ball");
		maxSpeed = 7.5f;

		b2CircleShape shape;
		shape.m_radius = sprite.getGlobalBounds().width / (2 * PHYSICS_SCALE);

		b2FixtureDef fixtureDef;
		fixtureDef.restitution = 1.0f;
		fixtureDef.density = .05f;
		fixtureDef.friction = 0.2f;
		fixtureDef.shape = &shape;
		body->CreateFixture(&fixtureDef);
		body->SetLinearDamping(maxSpeed);
	}

	Ball::~Ball()
	{
	}

	void Ball::update(float dt)
	{
	}
}
