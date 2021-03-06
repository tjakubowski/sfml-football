#pragma once

namespace Football
{
	class State
	{
	public:
		virtual void init() = 0;

		virtual void handleInput();
		virtual void update( float dt ) = 0;
		virtual void draw( float dt ) = 0;

		virtual void Pause() {}
		virtual void Resume() {}
	};
}
