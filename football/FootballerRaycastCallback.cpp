#include "FootballerRaycastCallback.hpp"
#include "GameObject.hpp"

namespace Football
{
	FootballerRaycastCallback::FootballerRaycastCallback() : gameObject(nullptr)
	{
	}

	float32 FootballerRaycastCallback::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
	{
		gameObject = static_cast<GameObject*>(fixture->GetBody()->GetUserData());

		return 0;
	}

	GameObject* FootballerRaycastCallback::getGameObject() const
	{
		return gameObject;
	}
}
