#include "CollisionListener.hpp"
#include "GameObject.hpp"

namespace Football
{
	void CollisionListener::BeginContact(b2Contact* contact)
	{
		const auto bodyA = contact->GetFixtureA()->GetBody();
		const auto bodyB = contact->GetFixtureB()->GetBody();

		auto gameObjectA = static_cast<GameObject*>(bodyA->GetUserData());
		auto gameObjectB = static_cast<GameObject*>(bodyB->GetUserData());

		gameObjectA->onCollision(gameObjectB);
		gameObjectB->onCollision(gameObjectA);
	}
}
