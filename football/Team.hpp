#pragma once
#include <string>
#include "Footballer.hpp"


namespace Football {
	class Team
	{
	public:
		Team(const std::string& name);
		~Team();
		void AddPlayer(std::unique_ptr<Footballer> footballer);

		std::string name;
		std::vector<std::unique_ptr<Footballer>> footballers;
	};
}
