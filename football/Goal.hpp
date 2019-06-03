#pragma once
#include "GameObject.hpp"

namespace Football
{

	class Goal : public GameObject
	{
	public:
		Goal(sf::Vector2f position, float width, float height);
		~Goal();
		void update(float dt) override;
		void draw() override;
	};


}
