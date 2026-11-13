#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Train.hpp"

class TrainFactory 
{
	public :
		static std::vector<std::unique_ptr<Train>> BuildTrains(const std::string &aFilename);
};
