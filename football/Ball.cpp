#include "Ball.hpp"

namespace Football
{
	Ball::Ball()
	{
		tag = "ball";
		deceleration = 0;
		acceleration = 0;
		maxSpeed = 0;

		sprite.setPosition(static_cast<sf::Vector2f>(GameData::getInstance()->window.getSize()) / 2.0f);
		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Ball"));
		collider = std::make_shared<CircleCollider>(this, sf::Vector2f(0, 0), sprite.getLocalBounds().width, true);
	}


	Ball::~Ball()
	{
	}

	void Ball::draw()
	{
		GameData::getInstance()->window.draw(sprite);

		collider->drawDebug();
	}

	void Ball::update(float dt)
	{
		std::cout << sprite.getPosition().x << " = " << sprite.getPosition().y;
	}

	void Ball::onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint)
	{
	}
}
