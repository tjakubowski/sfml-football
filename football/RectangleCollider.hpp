#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Collider.hpp"
#include "CircleCollider.hpp"

namespace Football
{
	class RectangleCollider : public Collider
	{
	public:
		RectangleCollider(GameObject* gameObject, sf::Vector2f offset, float width, float height, bool debug = false);
		~RectangleCollider() = default;

		void checkCollision(std::shared_ptr<Collider> checkCollider) override;

		void drawDebug() override;
	};
}
