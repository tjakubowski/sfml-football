#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(GameDataRef data) : _data(data)
	{

	}

	void Footballer::Draw() const
	{
		_data->window.draw(_sprite);
	}
}
