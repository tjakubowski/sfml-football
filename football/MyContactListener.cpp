#include "MyContactListener.hpp"
#include "GameObject.hpp"

namespace Football
{
	void MyContactListener::BeginContact(b2Contact* contact)
	{
		auto bodyA = contact->GetFixtureA()->GetBody();
		auto bodyB = contact->GetFixtureB()->GetBody();

		auto gameObjectA = static_cast<GameObject*>(bodyA->GetUserData());
		auto gameObjectB = static_cast<GameObject*>(bodyB->GetUserData());

		std::cout << gameObjectA->getTag() << " - " << gameObjectB->getTag() << std::endl;
	}

	void MyContactListener::EndContact(b2Contact* contact)
	{
		b2Fixture * fixtureA = contact->GetFixtureA();
		b2Fixture * fixtureB = contact->GetFixtureB();
	}
}
