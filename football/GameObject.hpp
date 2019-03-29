#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Helpers.hpp"

namespace Football
{
	class GameObject
	{
	protected:
		GameDataRef data;
		sf::Vector2f position;
		sf::Sprite sprite;
	public:
		GameObject(GameDataRef data);
		virtual ~GameObject();

		virtual void draw() = 0;
		virtual void update(float dt) = 0;

		friend bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b);
	};

}
