#pragma once
#include <Box2D/Box2D.h>
#include <iostream>
#include "SFMLDebugDraw.h"
#include "MyContactListener.hpp"

namespace Football
{
	class WorldManager
	{
	private:
		std::shared_ptr<b2World> world;
	public:
		std::shared_ptr<b2World> getWorld() const;
		WorldManager();
		~WorldManager();

		void update(float dt) const;
	};
}