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

	void Team::AddPoint()
	{
		points++;
	}

	int Team::GetPoints() const
	{
		return points;
	}

	std::vector<std::shared_ptr<Footballer>> const & Team::GetFootballers() const
	{
		return footballers;
	}

	void Team::AddPlayer(std::shared_ptr<Footballer> footballer)
	{
		footballers.push_back(std::move(footballer));
	}
}
