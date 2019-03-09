#include "Footballer.hpp"

namespace Football
{
	Footballer::Footballer(GameDataRef data) : _data(data)
	{
		_sprite.setTexture(_data->assets.GetTexture("Footballer"));
	}

	void Footballer::Draw()
	{
		_data->window.draw(_sprite);
	}
}

