#pragma once
#include "GameObject.hpp"
#include "CircleCollider.hpp"

namespace Football
{
	class Ball : public GameObject
	{
	public:
		Ball();
		~Ball();
		void draw() override;
		void update(float dt) override;
		void onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint) override;
	};
}
