#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Helpers.hpp"
#include "Collider.hpp"

namespace Football
{
	class Collider;

	class GameObject
	{
	protected:
		sf::Sprite sprite;
		std::shared_ptr<Collider> collider;
		float deceleration;
		float acceleration;
		float maxSpeed;
		sf::Vector2f force;
	public:
		GameObject();
		virtual ~GameObject() = default;

		virtual void draw() = 0;
		virtual void update(float dt) = 0;

		sf::Vector2f getPosition() const;
		std::shared_ptr<Collider> getCollider() const;

		virtual void move(sf::Vector2f direction, float dt);
		virtual void onCollision(GameObject* collisionGameObject) = 0;

		friend bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b);
	};

}
