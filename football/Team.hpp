#pragma once
#include <string>
#include "Footballer.hpp"


namespace Football {
	class Team
	{
	private:
		int points;

	public:
		Team(const std::string& name);
		~Team();
		void AddPlayer(std::unique_ptr<Footballer> footballer);
		void AddPoint();
		int GetPoints() const;

		std::string name;
		std::vector<std::unique_ptr<Footballer>> footballers;
	};
}
