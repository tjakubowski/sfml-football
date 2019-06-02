#pragma once
#include "InputManager.hpp"
#include "AssetManager.hpp"
#include "StateMachine.hpp"
#include "WorldManager.hpp"

namespace Football
{
	class GameData
	{
	private:
		static GameData* instance;
	public:
		GameData();
		~GameData();

		static GameData* getInstance();

		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager inputs;
		WorldManager worldManager;
	};
}
