#include "Team.hpp"

namespace Football
{
	Team::Team(Side side) : side(side)
	{
	}

	Team::~Team()
	{
	}

	std::shared_ptr<Goal> Team::getGoal() const
	{
		return goal;
	}

	Team::Side Team::getSide() const
	{
		return side;
	}

	std::vector<std::shared_ptr<Footballer>> Team::getFootballers() const
	{
		return footballers;
	}

	void Team::addFootballer(const std::shared_ptr<Footballer>& footballer)
	{
		footballers.push_back(footballer);
	}

	void Team::setGoal(const std::shared_ptr<Goal> goal)
	{
		this->goal = goal;
	}

	void Team::setFootballersGoalPart()
	{
		auto i = 0;

		for (auto footballer = footballers.begin(); footballer != footballers.end(); ++footballer, i++)
			footballer->get()->setGoalPart(i);
	}

	void Team::resetPosition() const
	{
		for (auto& footballer : getFootballers())
			footballer->resetPosition();
	}
}
