#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(std::string name) : name(name)
	{
		tag = "footballer";
		deceleration = 0.05;
		acceleration = 0.1;
		maxSpeed = 200;
	}

	void Footballer::draw()
	{
		GameData::getInstance()->window.draw(sprite);

		collider->drawDebug();
	}

	void Footballer::onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint)
	{
		// TODO: Refactor collisions
		auto direction = getPosition() - collisionGameObject->getPosition();
		const float forceMagnitude = magnitude(force);

		std::cout << forceMagnitude << std::endl;

		force = normalize(direction) * (forceMagnitude / 1.1f);
		collisionGameObject->force = -force;

		// Move if needed
		moveImmediately(normalize(collisionPoint - getPosition()) * -1.0f);
	}

	void Footballer::setName(const std::string& name) 
	{
		this->name = name;
	}
}
