#pragma once
#include "Footballer.hpp"

namespace Football
{
	class Player : public Footballer
	{
	private:
		void move() const;
	public:
		Player(sf::Vector2f position);
		~Player();
		void update(float dt) override;
	};

}
