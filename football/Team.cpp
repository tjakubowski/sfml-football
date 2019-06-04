#include "Team.hpp"

namespace Football
{
	Team::Team()
	{
	}

	Team::~Team()
	{
	}

	std::vector<std::shared_ptr<Footballer>> Team::getFootballers() const
	{
		return footballers;
	}

	void Team::addFootballer(const std::shared_ptr<Footballer>& footballer)
	{
		footballers.push_back(footballer);
	}

	void Team::resetPosition() const
	{
		for (auto &footballer : footballers)
			footballer->resetPosition();
	}
}
