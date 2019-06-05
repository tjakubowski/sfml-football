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

	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void update();

		sf::Vector2f getInputAxis(AxisKeys keysSetting = {sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Space}) const;

		bool isPressed(sf::Keyboard::Key key);
		bool isClicked(sf::IntRect rect, sf::Mouse::Button button, sf::RenderWindow & window) const;
		sf::Vector2i getMousePosition(sf::RenderWindow& window) const;
	};
}
