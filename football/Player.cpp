#include "Player.hpp"

namespace Football
{
	Player::Player(sf::Vector2f position, std::shared_ptr<Team> team, AxisKeys keys) : Footballer(position, team), keys(keys)
	{
	}

	Player::~Player()
	{
	}

	void Player::update(float dt)
	{
		Footballer::update(dt);

		move();

		if (GameData::getInstance()->inputs.getKeyDown(keys.shoot) && canShoot())
			shoot();
	}

	bool Player::canShoot()
	{
		return isCloseToBall();
	}

	void Player::move() const
	{
		const auto forceTemp = GameData::getInstance()->inputs.getInputAxis(keys);
		auto force = b2Vec2(forceTemp.x, forceTemp.y);
		force.Normalize();

		body->ApplyLinearImpulseToCenter(b2Vec2(force), true);
	}
}
