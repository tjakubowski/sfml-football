#include "WorldManager.hpp"

namespace Football
{
	WorldManager::WorldManager()
	{
		world = std::make_shared<b2World>(b2Vec2(0.f, 0.f));
	}

	WorldManager::~WorldManager()
	{
		
	}

	std::shared_ptr<b2World> WorldManager::getWorld() const
	{
		return world;
	}

	void WorldManager::update(float dt) const
	{
		world->Step(dt, 8, 3);
	}
}
