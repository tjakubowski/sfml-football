#pragma once
#include "Footballer.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{
	class Player : public Footballer
	{
	private:
		void HandleInput(float dt);
	public:
		Player(GameDataRef data);

		void Update(float dt) override;
	};
}
