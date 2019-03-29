#include "GameData.hpp"

GameData* GameData::instance = nullptr;

GameData::GameData()
{
}


GameData::~GameData()
{
}

GameData* GameData::getInstance()
{
	if (instance == nullptr)
		instance = new GameData();

	return instance;
}
