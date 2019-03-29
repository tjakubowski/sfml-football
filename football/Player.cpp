#include "Player.hpp"

namespace Football
{
	Player::Player(GameDataRef data, std::string name) : Footballer(data, name)
	{
		sprite.setTexture(this->data->assets.GetTexture("Player"));
	}

	void Player::update(float dt)
	{
		go(dt);
	}

	void Player::go(float dt)
	{
		move(data->inputs.getInputAxis(), dt);
	}

}
