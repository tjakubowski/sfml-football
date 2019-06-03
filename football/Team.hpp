#pragma once
#include "Footballer.hpp"
#include "Goal.hpp"

namespace Football
{
	class Goal;

	class Team
	{
	private:
		int points;
		std::shared_ptr<Goal> goal;
		std::vector<std::shared_ptr<Footballer>> footballers;
	public:
		Team();
		~Team();

		void setGoal(const std::shared_ptr<Goal>& goal);
		void addFootballer(const std::shared_ptr<Footballer>& footballer);
		void addPoint();

		int getPoints() const;
	};
}
