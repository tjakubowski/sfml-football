#pragma once
#include <string>
#include <vector>

namespace Football
{
	struct Score
	{
		int leftPoints;
		int rightPoints;
		long long timestamp;
	};

	class ScoreManager
	{
	private:
		bool loaded;
		std::string scoreFilename;
		std::vector<Score> scores;

		void load();
		void save();
	public:
		ScoreManager();
		~ScoreManager();

		std::vector<Score> getScores();
		void addScore(int leftPoints, int rightPoints);
	};

}
