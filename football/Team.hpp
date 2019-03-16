#pragma once
#include <string>
#include "Footballer.hpp"


namespace Football {
	class Team
	{
	private:
		int points;
		std::vector<std::unique_ptr<Footballer>> footballers;

	public:
		Team(const std::string& name);
		~Team();
		void AddPlayer(std::unique_ptr<Footballer> footballer);
		void AddPoint();
		int GetPoints() const;
		std::vector<std::unique_ptr<Footballer>> const& GetFootballers() const;

		std::string name;
	};
}
