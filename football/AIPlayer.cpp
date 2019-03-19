#include "AIPlayer.hpp"

namespace Football
{
	AIPlayer::AIPlayer(GameDataRef data, std::string name) : Footballer(data, name)
	{
		sprite.setTexture(data->assets.GetTexture("Footballer"));
	}

	void AIPlayer::update(float dt)
	{
		std::cout << "AI" << std::endl;
	}
}
