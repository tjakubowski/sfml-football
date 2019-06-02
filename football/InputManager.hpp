#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Common/b2Math.h>

namespace Football
{
	class InputManager
	{
	private:
		b2Vec2 inputAxis;
		void updateInputAxis();
	public:
		InputManager();
		~InputManager();

		void update();

		b2Vec2 getInputAxis() const;

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) const;
		sf::Vector2i getMousePosition(sf::RenderWindow& window) const;
	};
}
