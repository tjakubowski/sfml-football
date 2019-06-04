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

	bool InputManager::isPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}

	bool InputManager::isClicked(sf::IntRect rect, sf::Mouse::Button button, sf::RenderWindow & window) const
	{
		if(sf::Mouse::isButtonPressed(button))
		{
			if (rect.contains(sf::Mouse::getPosition(window)))
				return true;
		}

		return false;
	}

	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & window) const
	{
		return sf::Mouse::getPosition(window);
	}
}
