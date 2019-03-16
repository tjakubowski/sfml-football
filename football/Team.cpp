#include "Team.hpp"


namespace Football {

	Team::Team(const std::string& name) : name(name)
	{
		this->footballers = std::vector<std::unique_ptr<Footballer>>();
	}


	Team::~Team()
	{
	}

	void Team::AddPlayer(std::unique_ptr<Footballer> footballer)
	{
		footballers.push_back(std::move(footballer));
	}
}