#pragma once
#include "GameObject.hpp"

namespace Football
{
	class Footballer : public GameObject
	{
	public:
		Footballer(sf::Vector2f position);
		~Footballer();
		void draw() override;
		void update(float dt) override;
	};

}
