#pragma once
#include "InputManager.hpp"
#include "AssetManager.hpp"
#include "StateMachine.hpp"

class GameData
{
private:
	static GameData* instance;
public:
	GameData();
	~GameData();

	static GameData* getInstance();

	Football::StateMachine machine;
	sf::RenderWindow window;
	Football::AssetManager assets;
	Football::InputManager inputs;
};

