#pragma once
#include "Goal.hpp"
#include "Footballer.hpp"

namespace Football
{
	class Goal;
	class Footballer;

	class Team
	{
	public:
		enum Side { Left, Right };
	private:
		std::shared_ptr<Goal> goal;
		std::vector<std::shared_ptr<Footballer>> footballers;
		Side side;
	public:
		Side getSide() const;
		Team(Side side);
		~Team();

		std::shared_ptr<Goal> getOpponentGoal() const;
		std::shared_ptr<Goal> getGoal() const;
		std::vector<std::shared_ptr<Footballer>> getFootballers() const;
		void addFootballer(const std::shared_ptr<Footballer>& footballer);
		void setGoal(std::shared_ptr<Goal> goal);

		void setFootballersGoalPart();

		void resetPosition() const;
	};
}
