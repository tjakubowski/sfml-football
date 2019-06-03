#pragma once
#include "GameObject.hpp"

namespace Football
{
	class Ball : public GameObject
	{
	public:
		Ball(sf::Vector2f position);
		~Ball();
		void update(float dt) override;
		void onCollision(GameObject* collisionObject) override;
	};

}
