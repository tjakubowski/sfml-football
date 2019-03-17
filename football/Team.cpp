#include "Team.hpp"


namespace Football {

	Team::Team(const std::string& name) : name(name)
	{
		footballers = std::vector<std::shared_ptr<Footballer>>();
		points = 0;
	}


	Team::~Team()
	{
	}

	void Team::addPoint()
	{
		points++;
	}

	int Team::getPoints() const
	{
		return points;
	}

	std::vector<std::shared_ptr<Footballer>> const & Team::getFootballers() const
	{
		return footballers;
	}

	void Team::addPlayer(std::shared_ptr<Footballer> footballer)
	{
		footballers.push_back(std::move(footballer));
	}
}
