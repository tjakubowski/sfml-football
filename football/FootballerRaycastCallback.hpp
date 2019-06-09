#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include <Box2D/Dynamics/b2Fixture.h>

namespace Football
{
	class FootballerRaycastCallback : public b2RayCastCallback
	{
	public:
		float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) override;
	};
}
