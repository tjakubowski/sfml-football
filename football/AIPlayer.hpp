#pragma once
#include "Footballer.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{
	class AIPlayer : public Footballer
	{
	public:
		AIPlayer(std::string name);

		void update(float dt) override;
	};
}
