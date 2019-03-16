#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(GameDataRef data, std::string name) : _data(data) ,name(name)
	{

	}

	void Footballer::Draw() const
	{
		_data->window.draw(_sprite);
	}
	void Footballer::SetName(const std::string& name) 
	{
		this->name = name;
	}
}
