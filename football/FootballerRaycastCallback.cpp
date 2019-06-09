#include "FootballerRaycastCallback.hpp"
#include "GameObject.hpp"

namespace Football
{
	float32 FootballerRaycastCallback::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
	{
		const auto collisionObject = static_cast<GameObject*>(fixture->GetBody()->GetUserData());
		return collisionObject->getTag() == "ball";
	}
}
