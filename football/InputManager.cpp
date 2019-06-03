#include "InputManager.hpp"

namespace Football
{
	InputManager::InputManager()
	{
		inputAxis = sf::Vector2f(0, 0);
	}

	InputManager::~InputManager()
	{
	}

	void InputManager::update()
	{
		updateInputAxis();
	}

	void InputManager::updateInputAxis()
	{
		inputAxis = sf::Vector2f(0, 0);

		// Go left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			inputAxis.x = -1;

		// Go right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			inputAxis.x = 1;

		// Go up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			inputAxis.y = -1;

		// Go down
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			inputAxis.y = 1;
	}

	sf::Vector2f InputManager::getInputAxis() const
	{
		return inputAxis;
	}

	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window) const
	{
		if(sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (tempRect.contains(sf::Mouse::getPosition(window)))
				return true;
		}

		return false;
	}

	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & window) const
	{
		return sf::Mouse::getPosition(window);
	}
}
