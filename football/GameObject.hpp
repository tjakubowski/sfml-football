#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Helpers.hpp"

namespace Football
{
	class Collider;

	class GameObject
	{
	protected:
		float maxSpeed;
		sf::Sprite sprite;
		std::string tag;
		b2Body* body;
	public:
		GameObject(sf::Vector2f position, b2BodyType bodyType = b2_dynamicBody);
		virtual ~GameObject() = default;

		virtual void draw();
		virtual void update(float dt) = 0;

		std::string getTag() const;
	};

}
