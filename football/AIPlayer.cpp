#include "AIPlayer.hpp"

namespace Football
{
	AIPlayer::AIPlayer(std::string name) : Footballer(name)
	{
		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Footballer"));
	}

	void AIPlayer::update(float dt)
	{
		move(sf::Vector2f(1, 2), dt);
	}
}
