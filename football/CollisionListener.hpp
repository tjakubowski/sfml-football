#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>

namespace Football
{
	struct CollisionListener : public b2ContactListener
	{
		void BeginContact(b2Contact* contact) override;
	};

}
