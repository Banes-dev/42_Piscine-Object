#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../Network/Network.hpp"
#include "../Train/Train.hpp"

class Simulation 
{
	private :
		Network mNetwork;
		std::vector<std::unique_ptr<Train>> mTrains;

	public:
		Simulation() = default;

		void LoadNetwork(const std::string &aFilename);
		void LoadTrains(const std::string &aFilename);
		void Run();
};
