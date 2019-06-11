#include "ScoreManager.hpp"
#include <ctime>
#include <fstream>

namespace Football
{

	ScoreManager::ScoreManager()
	{
		loaded = false;
		scoreFilename = "saves.bin";
	}

	ScoreManager::~ScoreManager()
	{
	}

	std::vector<Score> ScoreManager::getScores()
	{
		if (!loaded)
			load();

		return scores;
	}

	void ScoreManager::load()
	{
		std::ifstream input(scoreFilename, std::ios::binary);

		scores.clear();

		Score score{};
		while (input.read(reinterpret_cast<char*> (&score), sizeof(score)))
			scores.push_back(score);

		loaded = true;
	}

	void ScoreManager::save()
	{
		std::ofstream output(scoreFilename, std::ios::binary);

		for(auto& score : scores)
			output.write(reinterpret_cast<char*> (&score), sizeof(score));
	}

	void ScoreManager::addScore(int leftPoints, int rightPoints)
	{
		if (!loaded)
			load();

		const auto timestamp = std::time(nullptr);
		scores.push_back({ leftPoints, rightPoints, timestamp});

		save();
	}
}
