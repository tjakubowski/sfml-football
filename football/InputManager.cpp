#include "InputManager.hpp"

namespace Football
{
	InputManager::InputManager()
	{
	}

	InputManager::~InputManager()
	{
	}

	void InputManager::update()
	{
	}

	sf::Vector2f InputManager::getInputAxis(AxisKeys keysSetting) const
	{
		auto inputAxis = sf::Vector2f(0, 0);

		// Go left
		if (sf::Keyboard::isKeyPressed(keysSetting.left))
			inputAxis.x = -1;

		// Go right
		else if (sf::Keyboard::isKeyPressed(keysSetting.right))
			inputAxis.x = 1;

		// Go up
		if (sf::Keyboard::isKeyPressed(keysSetting.up))
			inputAxis.y = -1;

		// Go down
		else if (sf::Keyboard::isKeyPressed(keysSetting.down))
			inputAxis.y = 1;

		return inputAxis;
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

	bool InputManager::getKeyUp(sf::Keyboard::Key key)
	{
		return keys.find(key) != keys.end() && keys[key] == KeyState::Up;
	}

	bool InputManager::getKey(sf::Keyboard::Key key)
	{
		return keys.find(key) != keys.end() && keys[key] == KeyState::Pressed;
	}

	bool InputManager::getKeyDown(sf::Keyboard::Key key)
	{
		return keys.find(key) != keys.end() && keys[key] == KeyState::Down;
	}

	void InputManager::addKeyEvent(sf::Keyboard::Key key)
	{
		// Key doesn't exist
		if (keys.find(key) == keys.end())
			keys[key] = KeyState::Down;
	}

	void InputManager::removeKeyEvent(sf::Keyboard::Key key)
	{
		// Key exists
		if (keys.find(key) != keys.end())
			keys[key] = KeyState::Up;
	}

	void InputManager::updateKeyEvents()
	{
		for (auto key = keys.begin(); key != keys.end();)
			if (key->second == KeyState::Down)
			{
				key->second = KeyState::Pressed;
				++key;
			}
			else if (key->second == KeyState::Up)
				keys.erase(key++);
			else
				++key;
	}
}
