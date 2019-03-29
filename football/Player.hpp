#pragma once
#include "DEFINITIONS.hpp"
#include "Footballer.hpp"

namespace Football
{
	class Player : public Footballer
	{
	public:
		Player(std::string name);

		void update(float dt) override;
		void go(float dt);
	};
}
