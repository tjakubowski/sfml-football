#pragma once
#include "GameObject.hpp"

namespace Football
{
	class Ball : public GameObject
	{
	public:
		Ball(sf::Vector2f position);
		~Ball();
		void draw() override;
		void update(float dt) override;
	};


}
