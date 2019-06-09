#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Helpers.hpp"
#include <Box2D/Box2D.h>
#include "Animation.hpp"

namespace Football
{
	class GameObject
	{
	protected:

		sf::Vector2f startPosition;
		float maxSpeed;
		std::unique_ptr<Animation> animation;
		sf::Sprite sprite;
		std::string tag;
		b2Body* body;

		virtual void setSpriteTexture(std::string textureName);
		virtual void setSpriteTextureOrigin();
	public:
		GameObject(sf::Vector2f position, b2BodyType bodyType = b2_dynamicBody);
		virtual ~GameObject() = default;

		virtual void draw();
		virtual void update(float dt) = 0;
		virtual void onCollision(GameObject* collisionObject) = 0;

		std::string getTag() const;
		sf::Vector2f getPosition() const;
		virtual float getWidth() const;
		virtual float getHeight() const;

		void resetPosition() const;

		friend bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b);
	};

}
