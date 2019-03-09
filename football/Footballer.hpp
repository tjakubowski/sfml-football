#pragma once
#include "Game.hpp"

namespace Football
{
	class Footballer
	{
	public:
		Footballer(GameDataRef data);

		void Draw();
	private:
		GameDataRef _data;

		sf::Sprite _sprite;
	};
}
