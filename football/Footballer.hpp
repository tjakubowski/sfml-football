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
	public:
		Footballer(std::string name);

		void setName(const std::string& name);

		void draw() override;

		void onCollision(GameObject* collisionGameObject) override;
	};
}
