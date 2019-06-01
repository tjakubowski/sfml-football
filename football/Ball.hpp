#pragma once
#include "GameObject.hpp"
#include "CircleCollider.hpp"

namespace Football
{
	class Ball : public GameObject
	{
	public:
		Ball(sf::Vector2f position);
		~Ball();
		void draw() override;
		void update(float dt) override;
		void onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint) override;
		void move(const float& dt);
	};
}
