#pragma once
#include "Footballer.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Football
{
	class AIPlayer : public Footballer
	{
	public:
		AIPlayer(GameDataRef data);

		void Update(float dt) override;
	};
}
