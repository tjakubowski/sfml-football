#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Helpers.hpp"

namespace Football
{
	class GameObject
	{
	protected:
		float maxSpeed;
		sf::Sprite sprite;
		std::string tag;
		b2Body* body;

		virtual void setSpriteTexture(std::string textureName);
	public:
		GameObject(sf::Vector2f position, b2BodyType bodyType = b2_dynamicBody);
		virtual ~GameObject() = default;

		virtual void draw();
		virtual void update(float dt) = 0;
		virtual void onCollision(GameObject* collisionObject) = 0;

		std::string getTag() const;
		sf::Vector2f getPosition() const;

		friend bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b);
	};

}
