#include "Player.hpp"

namespace Football
{
	Player::Player(sf::Vector2f position) : Footballer(position)
	{
	}

	Player::~Player()
	{
	}

	void Player::update(float dt)
	{
		move();
	}

	void Player::move() const
	{
		auto forceTemp = GameData::getInstance()->inputs.getInputAxis();
		auto force = b2Vec2(forceTemp.x, forceTemp.y);
		force.Normalize();

		body->ApplyLinearImpulseToCenter(b2Vec2(force), true);
	}
}
