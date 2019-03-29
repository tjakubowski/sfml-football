#pragma once
#include <string>
#include "Game.hpp"
#include "GameObject.hpp"

namespace Football
{
	class Footballer : public GameObject
	{
	protected:
		std::string name;
		float acceleration;
		float maxSpeed;
		sf::Vector2f force;

		void move(sf::Vector2f direction, float dt);
	public:
		Footballer(GameDataRef data, std::string name);

		void draw() override;

		void setName(const std::string& name);
	};
}
