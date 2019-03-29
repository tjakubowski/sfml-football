#include "Player.hpp"

namespace Football
{
	Player::Player(std::string name) : Footballer(name)
	{
		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Player"));
	}

	void Player::update(float dt)
	{
		go(dt);
	}

	void Player::go(float dt)
	{
		move(GameData::getInstance()->inputs.getInputAxis(), dt);
	}

}
