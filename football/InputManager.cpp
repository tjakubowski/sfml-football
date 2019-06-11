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

	bool InputManager::isClicked(sf::IntRect rect, sf::Mouse::Button button, sf::RenderWindow & window)
	{
		return getButtonDown(button) && rect.contains(sf::Mouse::getPosition(window));
	}

	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & window) const
	{
		return sf::Mouse::getPosition(window);
	}

	bool InputManager::getKeyUp(sf::Keyboard::Key key)
	{
		return keys.find(key) != keys.end() && keys[key] == InputState::Up;
	}

	bool InputManager::getKey(sf::Keyboard::Key key)
	{
		return keys.find(key) != keys.end() && keys[key] == InputState::Pressed;
	}

	bool InputManager::getKeyDown(sf::Keyboard::Key key)
	{
		return keys.find(key) != keys.end() && keys[key] == InputState::Down;
	}

	bool InputManager::getButtonUp(sf::Mouse::Button btn)
	{
		return buttons.find(btn) != buttons.end() && buttons[btn] == InputState::Up;
	}

	bool InputManager::getButton(sf::Mouse::Button btn)
	{
		return buttons.find(btn) != buttons.end() && buttons[btn] == InputState::Pressed;
	}

	bool InputManager::getButtonDown(sf::Mouse::Button btn)
	{
		return buttons.find(btn) != buttons.end() && buttons[btn] == InputState::Down;
	}

	void InputManager::addEvent(sf::Keyboard::Key key)
	{
		// Key doesn't exist
		if (keys.find(key) == keys.end())
			keys[key] = InputState::Down;
	}

	void InputManager::removeEvent(sf::Keyboard::Key key)
	{
		// Key exists
		if (keys.find(key) != keys.end())
			keys[key] = InputState::Up;
	}

	void InputManager::addEvent(sf::Mouse::Button btn)
	{
		// Button doesn't exist
		if (buttons.find(btn) == buttons.end())
			buttons[btn] = InputState::Down;
	}

	void InputManager::removeEvent(sf::Mouse::Button btn)
	{
		// Key exists
		if (buttons.find(btn) != buttons.end())
			buttons[btn] = InputState::Up;
	}

	void InputManager::updateEvents()
	{
		for (auto key = keys.begin(); key != keys.end();)
			if (key->second == InputState::Down)
			{
				key->second = InputState::Pressed;
				++key;
			}
			else if (key->second == InputState::Up)
				keys.erase(key++);
			else
				++key;

		for (auto btn = buttons.begin(); btn != buttons.end();)
			if (btn->second == InputState::Down)
			{
				btn->second = InputState::Pressed;
				++btn;
			}
			else if (btn->second == InputState::Up)
				buttons.erase(btn++);
			else
				++btn;
	}
}
