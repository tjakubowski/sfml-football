#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "Collider.hpp"

namespace Football
{
	class CircleCollider : public Collider
	{
	private:
		float radius;
	public:
		CircleCollider(GameObject* gameObject, sf::Vector2f offset, float width, bool debug = false);
		~CircleCollider() = default;

		void drawDebug() override;
	};
}
