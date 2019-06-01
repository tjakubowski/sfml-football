#pragma once
#include "DEFINITIONS.hpp"
#include "Footballer.hpp"

namespace Football
{
	class Player : public Footballer
	{
	public:
		Player(sf::Vector2f position, std::string name);

		void update(float dt) override;
		void go(float dt);
	};
}
