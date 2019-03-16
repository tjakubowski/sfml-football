#pragma once
#include "Game.hpp"
#include <string>

namespace Football
{
	class Footballer
	{
	public:
		Footballer(GameDataRef data, std::string name);

		void Draw() const;
		virtual void Update(float dt) = 0;
		void SetName(const std::string& name);
	protected:
		GameDataRef _data;
		std::string name;

		sf::Sprite _sprite;
	};
}
