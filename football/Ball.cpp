#include "Ball.hpp"

namespace Football
{
	Ball::Ball(sf::Vector2f position) : GameObject(position, b2_dynamicBody)
	{
		tag = "ball";

		GameObject::setSpriteTexture("ball");
		damping = 6.5f;

		b2CircleShape shape;
		shape.m_radius = sprite.getGlobalBounds().width / (2 * PHYSICS_SCALE);

		b2FixtureDef fixtureDef;
		fixtureDef.restitution = 1.0f;
		fixtureDef.density = .02f;
		fixtureDef.friction = 0;
		fixtureDef.shape = &shape;
		body->CreateFixture(&fixtureDef);
		body->SetLinearDamping(damping);
		body->SetBullet(true);
	}

	Ball::~Ball()
	{
	}

	void Ball::update(float dt)
	{
	}

	void Ball::onCollision(GameObject* collisionObject)
	{
	}

	void Ball::getKickFrom(sf::Vector2f fromVector, float force) const
	{
		const auto impulseForce = normalize(getPosition() - fromVector) * force;
		body->ApplyLinearImpulseToCenter(b2Vec2(impulseForce.x / PHYSICS_SCALE, impulseForce.y / PHYSICS_SCALE), true);
	}
}
