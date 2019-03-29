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

		void addPlayer(std::shared_ptr<Footballer> footballer);
		void addPoint();
		int getPoints() const;
		std::vector<std::shared_ptr<Footballer>> const& getFootballers() const;

		std::string name;
	};
}
