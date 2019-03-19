#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(GameDataRef data, std::string name) : GameObject(data), name(name)
	{
		position = sf::Vector2f(250, 250);
		sprite.setPosition(position);
	}

	void Footballer::draw()
	{
		data->window.draw(sprite);
	}

	void Footballer::setName(const std::string& name) 
	{
		this->name = name;
	}
}
