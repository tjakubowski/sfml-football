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
		auto force = GameData::getInstance()->inputs.getInputAxis();
		force.Normalize();

		body->ApplyLinearImpulseToCenter(b2Vec2(force), true);
	}
}
