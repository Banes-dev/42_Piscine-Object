#include "Simulation.hpp"

#include <stdexcept>
#include <iostream>

#include "../Network/NetworkFactory.hpp"
#include "../Train/TrainFactory.hpp"
#include "DijkstraPathfinder.hpp"
#include "../Event/RandomEventGenerator.hpp"


void Simulation::LoadNetwork(const std::string &aFilename)
{
    mNetwork = NetworkFactory::BuildNetwork(aFilename);
}

void Simulation::LoadTrains(const std::string &aFilename)
{
    mTrains = TrainFactory::BuildTrains(aFilename);

	// Check if the departure and arrival stations exist
    for (const auto &vTrain : mTrains)
    {
        if (!mNetwork.GetNode(vTrain->GetDepStation()) || !mNetwork.GetNode(vTrain->GetArrStation()))
            throw std::runtime_error("Train " + vTrain->GetName() + " has an invalid departure or arrival station.");
    }
}

// void Simulation::Run()
std::map<std::string, int> Simulation::Run()
{
    DijkstraPathfinder vPathfinder;
	RandomEventGenerator vEventGen;

    // Calculate paths for all trains before starting
    for (auto &vTrain : mTrains)
    {
        Node *vStart = mNetwork.GetNode(vTrain->GetDepStation());
        Node *vEnd = mNetwork.GetNode(vTrain->GetArrStation());
        
        std::vector<Rail *> vPath = vPathfinder.CalculatePath(mNetwork, vStart, vEnd);
        vTrain->SetPath(vPath);
		vEventGen.AddObserver(vTrain.get());
    }

    std::cout << "Starting simulation with " << mTrains.size() << " trains..." << std::endl;

    int vCurrentTimeMinutes = 0; // Starts at 00h00
    bool vSimulationRunning = true;

    // Main simulation loop
    while (vSimulationRunning)
    {
        vSimulationRunning = false;

		vEventGen.Generate(mNetwork);

        for (auto &vTrain : mTrains)
        {
            if (vTrain->IsActive())
                vTrain->DetectObstacles(mTrains);
        }

        for (auto &vTrain : mTrains)
        {
            if (!vTrain->HasFinished())
            {
                vSimulationRunning = true;

                if (!vTrain->IsActive())
                    vTrain->TryStart(vCurrentTimeMinutes);

                if (vTrain->IsActive())
                {
					// Update physical movement for 1 minute (aDeltaTimeMinutes = 1.0)
                    vTrain->UpdatePhysics(1.0);
                    vTrain->WriteTickLog(vCurrentTimeMinutes);
                }
            }
        }

        vCurrentTimeMinutes++;
    }
	// Return a map of train names to their actual travel times
	std::map<std::string, int> vResults;
    for (const auto &vTrain : mTrains)
        vResults[vTrain->GetName()] = vTrain->GetActualTravelTime();
    return vResults;
}
