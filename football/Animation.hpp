#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace Football
{
	class Animation
	{
	private:
		sf::Sprite* sprite;

		int currentColumn;
		int columns;

		float currentTime;
		float switchTime;

		void updateTexturePosition() const;
	public:
		Animation(std::string textureName, sf::Sprite* sprite, int columns, float switchTime);
		~Animation();
		void update(float dt);
	};
}
