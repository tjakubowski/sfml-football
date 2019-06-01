#pragma once
#include "GameObject.hpp"

namespace Football
{
	class Obstacle : public GameObject
	{
	public:
		Obstacle(sf::Vector2f position, sf::Vector2f size);
		~Obstacle();
		void draw() override;
		void update(float dt) override;
		void onCollision(GameObject* collisionGameObject, sf::Vector2f collisionPoint) override;
	};
}

