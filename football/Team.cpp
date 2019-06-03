#include "Team.hpp"

namespace Football
{
	Team::Team()
	{
	}

	Team::~Team()
	{
	}

	void Team::addFootballer(const std::shared_ptr<Footballer>& footballer)
	{
		footballers.push_back(footballer);
	}
}
