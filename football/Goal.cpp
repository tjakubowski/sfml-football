#include "Goal.hpp"

namespace Football
{
	Goal::Goal()
	{
		deceleration = 0;
		acceleration = 0;
		maxSpeed = 0;

		sprite.setPosition(sf::Vector2f(10, 220));
		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Goal"));
		collider = std::make_shared<RectangleCollider>(this, sf::Vector2f(0, 0), sprite.getLocalBounds().width, sprite.getLocalBounds().height, true);
	}


	Goal::~Goal()
	{
	}

	void Goal::draw()
	{
		GameData::getInstance()->window.draw(sprite);

		collider->drawDebug();
	}

	void Goal::update(float dt)
	{
	}

	void Goal::onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint)
	{

	}
}
