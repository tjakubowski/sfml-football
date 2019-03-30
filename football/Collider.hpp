#pragma once
#include <SFML/System/Vector2.hpp>
#include "GameObject.hpp"
#include <iostream>

namespace Football
{
	class GameObject;

	class Collider
	{
	protected:
		GameObject* gameObject;
		sf::Vector2f offset;
		float width;
		float height;
		bool debug;
	public:
		Collider(GameObject* gameObject, sf::Vector2f offset, float width, float height, bool debug = false);
		virtual ~Collider() = default;

		void setDebug(bool debug);


		float getWidth() const;
		float getHeight() const;
		sf::Vector2f getPosition() const;
		GameObject* getGameObject() const;

		virtual void checkCollision(std::shared_ptr<Collider> checkCollider) = 0;

		virtual void drawDebug() = 0;
		void draw();
	};
}
