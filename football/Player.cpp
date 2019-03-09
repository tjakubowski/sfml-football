#include "Player.hpp"

namespace Football
{
	Player::Player(GameDataRef data) : Footballer(data)
	{
		_sprite.setTexture(_data->assets.GetTexture("Player"));
	}

	void Player::Update(float dt)
	{
		HandleInput(dt);
	}

	void Player::HandleInput(float dt)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_sprite.move(-FOOTBALLER_SPEED * dt, .0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_sprite.move(FOOTBALLER_SPEED * dt, .0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_sprite.move(.0f, -FOOTBALLER_SPEED * dt);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_sprite.move(.0f, FOOTBALLER_SPEED * dt);
		}
	}
}
