#pragma once
#include "Footballer.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{
	class Player : public Footballer
	{
	public:
		Player(GameDataRef data, std::string name);

		void update(float dt) override;
		void go(float dt);
	};
}
