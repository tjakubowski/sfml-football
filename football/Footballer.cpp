#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(std::string name) : name(name)
	{
		sprite.setPosition(sf::Vector2f(250, 250));
		deceleration = 0.05;
		acceleration = 0.1;
		maxSpeed = 200;
	}

	void Footballer::draw()
	{
		GameData::getInstance()->window.draw(sprite);

		collider->drawDebug();
	}

	void Footballer::onCollision(GameObject* collisionGameObject)
	{
		// TODO: Collision handling
	}

	void Footballer::setName(const std::string& name) 
	{
		this->name = name;
	}
}
