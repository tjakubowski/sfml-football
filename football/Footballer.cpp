#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(GameDataRef data, std::string name) : _data(data) ,name(name)
	{
		position = sf::Vector2f(250, 250);
		_sprite.setPosition(position);
	}

	void Footballer::Draw() const
	{
		_data->window.draw(_sprite);
	}

	void Footballer::SetName(const std::string& name) 
	{
		this->name = name;
	}

	bool operator<(std::shared_ptr<Footballer>& a, std::shared_ptr<Footballer>& b)
	{
		return a->position.y < b->position.y;
	}
}
