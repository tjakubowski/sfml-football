#include "AIPlayer.hpp"

namespace Football
{
	AIPlayer::AIPlayer(std::string name) : Footballer(name)
	{
		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Footballer"));
		collider = std::make_shared<CircleCollider>(this, sf::Vector2f(0, 20), sprite.getLocalBounds().width, true);
	}

	void AIPlayer::update(float dt)
	{
		move(sf::Vector2f(1, 2), dt);
	}
}
