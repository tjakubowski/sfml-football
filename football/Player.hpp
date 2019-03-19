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

		void handleInput();
		void handleAxisInput();
		sf::Vector2f getMoveDirection() const;
	public:
		Player(GameDataRef data, std::string name);

		void move(float dt);
		void update(float dt) override;
	};
}
