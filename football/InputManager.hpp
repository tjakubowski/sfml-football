#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Common/b2Math.h>

namespace Football
{
	class InputManager
	{
	private:
		sf::Vector2f inputAxis;
		void updateInputAxis();
	public:
		InputManager();
		~InputManager();

		void update();

		sf::Vector2f getInputAxis() const;

		bool isPressed(sf::Keyboard::Key key);
		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) const;
		sf::Vector2i getMousePosition(sf::RenderWindow& window) const;
	};
}
