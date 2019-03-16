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
		sf::Vector2f position;
	protected:
		GameDataRef _data;

		std::string name;

		sf::Sprite _sprite;
	};

	bool operator< (std::shared_ptr<Footballer> &a, std::shared_ptr<Footballer> &b);
}
