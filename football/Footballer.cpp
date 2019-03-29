#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(std::string name) : name(name), deceleration(0.05), acceleration(0.1), maxSpeed(150)
	{
		collider = std::make_shared<CircleCollider>(this, sf::Vector2f(10, 10), sprite.getLocalBounds().width, true);
		sprite.setPosition(sf::Vector2f(250, 250));
	}

	void Footballer::draw()
	{
		GameData::getInstance()->window.draw(sprite);

		collider->drawDebug();
	}

	void Footballer::setName(const std::string& name) 
	{
		this->name = name;
	}

	void Footballer::move(sf::Vector2f direction, float dt)
	{
		// Slow down
		if(isZero(direction))
			force -= force * deceleration;
		else
			force = clampMagnitude(force + normalize(direction) * acceleration, 1);

		// Stop completely
		if (isZero(force))
			return;

		const auto finalMove = force * maxSpeed * dt;

		sprite.move(finalMove);
	}
}
