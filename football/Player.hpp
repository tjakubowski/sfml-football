#pragma once
#include "Footballer.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{
	class Player : public Footballer
	{
	private:
		void handleInput(float dt);
	public:
		Player(GameDataRef data, std::string name);

		void update(float dt) override;
	};
}
