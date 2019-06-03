#pragma once
#include "GameObject.hpp"

namespace Football
{
	class Obstacle : public GameObject
	{
	protected:
		void setSpriteTexture(std::string textureName) override;
	public:
		Obstacle(sf::Vector2f position, float width, float height);
		~Obstacle();
		void update(float dt) override;
		void onCollision(GameObject* collisionObject) override;
	};
}
