#include "Ball.hpp"

namespace Football
{
	Ball::Ball(sf::Vector2f position) : GameObject(position, b2BodyType::b2_dynamicBody)
	{
		maxSpeed = 7.5f;

		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Ball"));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

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

	void Ball::draw()
	{
		sprite.setPosition(PHYSICS_SCALE * body->GetPosition().x, PHYSICS_SCALE * body->GetPosition().y);
		sprite.setRotation(body->GetAngle() * 180 / b2_pi);
		GameData::getInstance()->window.draw(sprite);
	}

	void Ball::update(float dt)
	{
	}
}
