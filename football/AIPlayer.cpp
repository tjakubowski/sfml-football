#include "AIPlayer.hpp"

namespace Football
{
	AIPlayer::AIPlayer(GameDataRef data, std::string name) : Footballer(data, name)
	{
		_sprite.setTexture(_data->assets.GetTexture("Footballer"));
	}

	void AIPlayer::Update(float dt)
	{
		std::cout << "AI" << std::endl;
	}
}
