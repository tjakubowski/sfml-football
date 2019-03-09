#pragma once
#include "Game.hpp"

namespace Football
{
	class Footballer
	{
	public:
		Footballer(GameDataRef data);

		void Draw() const;
		virtual void Update(float dt) = 0;
	protected:
		GameDataRef _data;

		sf::Sprite _sprite;
	};
}
