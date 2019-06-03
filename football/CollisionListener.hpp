#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include <iostream>
#include <Box2D/Dynamics/Contacts/b2Contact.h>

namespace Football
{
	struct CollisionListener : public b2ContactListener
	{
		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};

}
