#include "Player.hpp"

namespace Football
{
	Player::Player(sf::Vector2f position, std::shared_ptr<Team> team) : Footballer(position, team)
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
		const auto forceTemp = GameData::getInstance()->inputs.getInputAxis();
		auto force = b2Vec2(forceTemp.x, forceTemp.y);
		force.Normalize();

		body->ApplyLinearImpulseToCenter(b2Vec2(force), true);
	}
}
