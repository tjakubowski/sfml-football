#pragma once
#include "GameObject.hpp"
#include "RectangleCollider.hpp"

namespace Football
{
	class Goal :
		public Football::GameObject
	{
	public:
		Goal();
		~Goal();
		void draw() override;
		void update(float dt) override;
		void onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint) override;
	};

}
