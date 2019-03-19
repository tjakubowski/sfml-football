#include "Player.hpp"

namespace Football
{
	Player::Player(GameDataRef data, std::string name) : Footballer(data, name)
	{
		sprite.setTexture(this->data->assets.GetTexture("Player"));
		inputAxis = sf::Vector2f(0, 0);
		maxSpeed = 200.0f;
		speedDelta = 0.05f;
	}

	void Player::update(float dt)
	{
		handleInput();
		move(dt);
	}

	void Player::handleInput()
	{
		handleAxisInput();
	}

	void Player::handleAxisInput()
	{
		float x = 0;
		float y = 0;
		inputAxisRaw = sf::Vector2f(0, 0);

		// Go left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			x = -speedDelta;
			inputAxisRaw.x = -1;
		}
		// Go right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			x = speedDelta;
			inputAxisRaw.x = 1;
		}
		// Slow down
		else if (inputAxis.x != 0.0f)
			x = inputAxis.x > 0.0f ? -speedDelta : speedDelta;

		// Go up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			y = -speedDelta;
			inputAxisRaw.y = -1;
		}
		// Go down
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			y = speedDelta;
			inputAxisRaw.y = 1;
		}
		// Slow down
		else if (inputAxis.y != 0.0f)
			y = inputAxis.y > 0.0f ? -speedDelta : speedDelta;

		// Clamp -1 < value < 1
		inputAxis.x = std::clamp(inputAxis.x + x, -1.0f, 1.0f);
		inputAxis.y = std::clamp(inputAxis.y + y, -1.0f, 1.0f);

		// Eliminate float precision problem
		if (std::abs(inputAxis.x) < speedDelta)
			inputAxis.x = 0;
		if (std::abs(inputAxis.y) < speedDelta)
			inputAxis.y = 0;
	}

	sf::Vector2f Player::getMoveDirection() const
	{
		if (inputAxis.x == 0.0 && inputAxis.y == 0.0)
			return sf::Vector2f(0, 0);

		const auto directionVector = sf::Vector2f(inputAxis.x != 0.0f ? 1 : 0, inputAxis.y != 0.0f ? 1 : 0);
		const auto directionVectorLength = std::sqrt(directionVector.x * directionVector.x + directionVector.y * directionVector.y);

		return directionVectorLength > 0 ? directionVector / directionVectorLength : directionVector;
	}

	void Player::move(float dt)
	{
		// Normalized input axis vector
		const auto directionVector = getMoveDirection();

		// Create final move vector
		const auto transformVector = sf::Vector2f(directionVector.x * inputAxis.x, directionVector.y * inputAxis.y) * maxSpeed * dt;

		position += transformVector;
		sprite.setPosition(position);
	}


}
