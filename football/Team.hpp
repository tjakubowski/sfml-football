#pragma once
#include "Footballer.hpp"
#include "Goal.hpp"

namespace Football
{
	class Goal;

	class Team
	{
	private:
		std::vector<std::shared_ptr<Footballer>> footballers;
	public:
		Team();
		~Team();

		std::vector<std::shared_ptr<Footballer>> getFootballers() const;
		void addFootballer(const std::shared_ptr<Footballer>& footballer);

		void resetPosition() const;
	};
}
