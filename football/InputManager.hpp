#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Common/b2Math.h>

namespace Football
{
	struct AxisKeys
	{
		sf::Keyboard::Key up;
		sf::Keyboard::Key down;
		sf::Keyboard::Key right;
		sf::Keyboard::Key left;
		sf::Keyboard::Key shoot;
	};

	enum KeyState
	{
		Down,
		Pressed,
		Up
	};

	class InputManager
	{
	private:
		std::map< sf::Keyboard::Key, KeyState> keys;
	public:
		InputManager();
		~InputManager();

		void update();

		sf::Vector2f getInputAxis(AxisKeys keysSetting = {sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Space}) const;

		bool isClicked(sf::IntRect rect, sf::Mouse::Button button, sf::RenderWindow & window) const;
		sf::Vector2i getMousePosition(sf::RenderWindow& window) const;

		bool getKeyUp(sf::Keyboard::Key key);
		bool getKey(sf::Keyboard::Key key);
		bool getKeyDown(sf::Keyboard::Key key);

		void addKeyEvent(sf::Keyboard::Key key);
		void removeKeyEvent(sf::Keyboard::Key key);

		void updateKeyEvents();
	};
}
