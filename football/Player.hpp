#pragma once
#include "Footballer.hpp"

namespace Football
{
	class Player final : public Footballer
	{
	private:
		void move() const;
	public:
		Player(sf::Vector2f position, std::shared_ptr<Team> team);
		~Player();
		void update(float dt) override;
	protected:
		bool canShoot() override;
	};

}
