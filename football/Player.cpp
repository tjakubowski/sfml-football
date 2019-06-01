#include "Player.hpp"

namespace Football
{
	Player::Player(sf::Vector2f position, std::string name) : Footballer(position, name)
	{
		sprite.setTexture(GameData::getInstance()->assets.GetTexture("Player"));
		collider = std::make_shared<CircleCollider>(this, sf::Vector2f(0, 20), sprite.getLocalBounds().width, true);
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
