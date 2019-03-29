#pragma once
#include <SFML/System/Vector2.hpp>
#include "GameObject.hpp"

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

		sf::Vector2f getPosition() const;

		virtual void drawDebug() = 0;
		void draw();
	};
}
