#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "Collider.hpp"
#include "RectangleCollider.hpp"

namespace Football
{
	class CircleCollider : public Collider
	{
	public:
		CircleCollider(GameObject* gameObject, sf::Vector2f offset, float width, bool debug = false);
		~CircleCollider() = default;

		float getRadius() const;
		sf::Vector2f getCircleCenter() const;

		void checkCollision(std::shared_ptr<Collider> checkCollider) override;

		void drawDebug() override;
	};
}
