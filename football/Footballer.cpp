#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(GameDataRef data, std::string name) : GameObject(data), name(name), acceleration(0.1), deceleration(0.05), maxSpeed(150)
	{

		sprite.setPosition(sf::Vector2f(250, 250));
	}

	void Footballer::draw()
	{
		data->window.draw(sprite);
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
