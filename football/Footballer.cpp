#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(sf::Vector2f position) : GameObject(position, b2BodyType::b2_dynamicBody)
	{
		maxSpeed = 5.0f;

		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Footballer"));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

		b2CircleShape shape;
		shape.m_radius = sprite.getGlobalBounds().width / (2 * PHYSICS_SCALE);
		shape.m_p.Set(0, sprite.getGlobalBounds().height / (2 * PHYSICS_SCALE) - shape.m_radius);

		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.5f;
		fixtureDef.friction = 0.8f;
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
}
