#pragma once
#include "Game.hpp"
#include <string>
#include "GameObject.hpp"

namespace Football
{
	class Footballer : public GameObject
	{
	public:
		Footballer(GameDataRef data, std::string name);
		void draw() override;
		void setName(const std::string& name);

	protected:
		std::string name;
		sf::Sprite sprite;
	};
}
