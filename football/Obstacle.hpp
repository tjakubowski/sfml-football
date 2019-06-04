#pragma once
#include "GameObject.hpp"

namespace Football
{
	class Obstacle : public GameObject
	{
	protected:
		void setSpriteTexture(std::string textureName) override;
		float width;
		float height;
	public:
		Obstacle(sf::Vector2f position, float width, float height);
		~Obstacle();
		void update(float dt) override;
		void onCollision(GameObject* collisionObject) override;
		float getWidth() const override;
		float getHeight() const override;
	};
}
