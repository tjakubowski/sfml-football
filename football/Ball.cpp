#include "Ball.hpp"

namespace Football
{
	Ball::Ball()
	{
		tag = "ball";
		deceleration = 0.04;
		acceleration = 0.15;
		maxSpeed = 300;

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
		move(dt);
	}

	void Ball::move(const float& dt)
	{
		// Stop completely
		if (isZero(force))
			return;

		// Slow down
		force -= force * deceleration;

		const auto finalMove = force * maxSpeed * dt;

		sprite.move(finalMove);
	}

	void Ball::onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint)
	{
		if(collisionGameObject->getTag() == "footballer")
			force = normalize(getPosition() - collisionPoint) * static_cast<float>(magnitude(collisionGameObject->force)) * 1.5f;
	}
}
