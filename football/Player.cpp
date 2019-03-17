#include "Player.hpp"

namespace Football
{
	Player::Player(GameDataRef data, std::string name) : Footballer(data, name)
	{
		sprite.setTexture(this->data->assets.GetTexture("Player"));
	}

	void Player::update(float dt)
	{
		handleInput(dt);
	}

	void Player::handleInput(float dt)
	{
		int x = 0;
		int y = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			x = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			x = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			y = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			y = 1;

		const auto transformVector = sf::Vector2f(x, y) * FOOTBALLER_SPEED * dt;

		position += transformVector;
		sprite.setPosition(position);
	}
}
