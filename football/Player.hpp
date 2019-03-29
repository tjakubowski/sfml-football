#pragma once
#include "Footballer.hpp"
#include "DEFINITIONS.hpp"

namespace Football
{
	class Player : public Footballer
	{
	private:
		sf::Vector2f inputAxis;
		sf::Vector2f inputAxisRaw;
		float maxSpeed;
		float speedDelta;
	public:
		Player(GameDataRef data, std::string name);

		void update(float dt) override;
		void go(float dt);
	};
}
