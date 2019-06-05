#pragma once
#include "Footballer.hpp"

namespace Football
{
	class Player final : public Footballer
	{
	private:
		void move() const;
		AxisKeys keys;
	public:
		Player(sf::Vector2f position, std::shared_ptr<Team> team, AxisKeys keys = {sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Space });
		~Player();
		void update(float dt) override;
	protected:
		bool canShoot() override;
	};

}
