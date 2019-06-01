#include "Goal.hpp"

namespace Football
{
	Goal::Goal(sf::Vector2f position) : GameObject(position)
	{
		tag = "goal";
		deceleration = 0;
		acceleration = 0;
		maxSpeed = 0;

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
