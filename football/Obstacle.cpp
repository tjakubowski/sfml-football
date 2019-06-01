#include "Obstacle.hpp"
#include "RectangleCollider.hpp"

namespace Football
{
	Obstacle::Obstacle(sf::Vector2f position, sf::Vector2f size) : GameObject(position)
	{
		tag = "obstacle";
		deceleration = 0;
		acceleration = 0;
		maxSpeed = 0;

		collider = std::make_shared<RectangleCollider>(this, sf::Vector2f(0, 0), size.x, size.y, true);
	}

	Obstacle::~Obstacle()
	{
	}

	void Obstacle::draw()
	{
		collider->drawDebug();
	}

	void Obstacle::update(float dt)
	{
	}

	void Obstacle::onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint)
	{
	}
}
