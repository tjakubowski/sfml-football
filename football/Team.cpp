#include "Team.hpp"

namespace Football
{
	Team::Team()
	{
		goal = nullptr;
		points = 0;
	}

	Team::~Team()
	{
	}

	void Team::setGoal(const std::shared_ptr<Goal>& goal)
	{
		this->goal = goal;
	}

	void Team::addFootballer(const std::shared_ptr<Footballer>& footballer)
	{
		footballers.push_back(footballer);
	}

	void Team::addPoint()
	{
		points++;
	}

	int Team::getPoints() const
	{
		return points;
	}
}
