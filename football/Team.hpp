#pragma once
#include <string>
#include "Footballer.hpp"


namespace Football {
	class Team
	{
	private:
		int points;
		std::vector<std::shared_ptr<Footballer>> footballers;

	public:
		Team(const std::string& name);
		~Team();
		void AddPlayer(std::shared_ptr<Footballer> footballer);
		void AddPoint();
		int GetPoints() const;
		std::vector<std::shared_ptr<Footballer>> const& GetFootballers() const;

		std::string name;
	};
}
