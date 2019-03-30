#pragma once
#include <string>
#include "GameObject.hpp"
#include "CircleCollider.hpp"

namespace Football
{
	class Footballer : public GameObject
	{
	protected:
		std::string name;
		float deceleration;
		float acceleration;
		float maxSpeed;
		sf::Vector2f force;

		void move(sf::Vector2f direction, float dt);
	public:
		Footballer(std::string name);

		void setName(const std::string& name);

		void draw() override;

		void onCollision(GameObject* collisionGameObject) override;
	};
}
