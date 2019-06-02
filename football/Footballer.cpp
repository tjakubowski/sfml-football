#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(sf::Vector2f position) : GameObject(position, b2BodyType::b2_dynamicBody)
	{
		maxSpeed = 5.0f;

		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Footballer"));

		b2CircleShape shape;

		b2FixtureDef fixtureDef;
		fixtureDef.density = .1f;
		fixtureDef.friction = 0.2f;
		fixtureDef.shape = &shape;
		body->CreateFixture(&fixtureDef);
		body->SetLinearDamping(maxSpeed);
	}

	Footballer::~Footballer()
	{
		
	}

	void Footballer::draw()
	{
		sprite.setPosition(PHYSICS_SCALE * body->GetPosition().x, PHYSICS_SCALE * body->GetPosition().y);
		sprite.setRotation(body->GetAngle() * 180 / b2_pi);
		GameData::getInstance()->window.draw(sprite);
	}

	void Footballer::update(float dt)
	{
	}
}
