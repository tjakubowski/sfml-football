#include "WorldManager.hpp"

namespace Football
{
	WorldManager::WorldManager()
	{
		world = std::make_unique<b2World>(b2Vec2(0.f, 9.8f));
	}

	WorldManager::~WorldManager()
	{
	}

	void WorldManager::update(float dt) const
	{
		world->Step(dt, 8, 3);
	}
}
