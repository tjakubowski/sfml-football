#pragma once

#include <SFML/Graphics.hpp>

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

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) const;
		sf::Vector2i getMousePosition(sf::RenderWindow& window) const;
	};
}