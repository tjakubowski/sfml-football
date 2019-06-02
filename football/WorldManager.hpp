#pragma once
#include <Box2D/Box2D.h>
#include <iostream>

namespace Football
{
	class WorldManager
	{
	private:
		std::unique_ptr<b2World> world;
	public:
		WorldManager();
		~WorldManager();

		void update(float dt) const;
	};
}