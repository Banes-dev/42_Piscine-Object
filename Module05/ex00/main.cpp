#include <iostream>
#include <string>
#include <map>

#include "Color.hpp"
#include "Simulation/Simulation.hpp"
#include "Simulation/TimeUtils.hpp"


int main(int aArgc, char **aArgv)
{
	if (aArgc == 2 && std::string(aArgv[1]) == "-help")
	{
		std::cout << Cyan << "\n--- Help : How to create input files ---\n" << Reset_Color
              << Purple << "1. Rail network (.rail) format:\n" << Reset_Color << "   Node [CityName]\n" << "   Rail [CityA] [CityB] [Length_km] [MaxSpeed_kmh]\n"
              << Purple << "2. Trains (.train) format:\n" << Reset_Color
              << "   [Name] [Weight_t] [Friction] [MaxAccel_kN] [MaxBrake_kN] [DepCity] [ArrCity] [Time] [StopDuration]\n"
              << "   Example : TrainAB 80 0.05 356.0 30.0 CityA CityB 14h10 00h10\n" << std::endl;
		return 0;
	}
	// Check args
	if (aArgc != 3)
	{
		std::cerr << Deny << Red << " Error wrong args\n" << Reset_Color;
		std::cerr << "Usage: ./Train_yourself [network.rail] [trains.train]\n" << "       ./Train_yourself -help\n";
		return 1;
	}

	// Parse info file & launch the simulation
	try
    {
        std::string vRailFile = aArgv[1];
        std::string vTrainFile = aArgv[2];

		int vNbRuns = 10;
        std::map<std::string, int> vTotalTimes;

        std::cout << "Running simulation " << vNbRuns << " times to compute average...\n";

        for (int i = 0; i < vNbRuns; ++i)
        {
            Simulation vSim;
            vSim.LoadNetwork(vRailFile);
            vSim.LoadTrains(vTrainFile);
            
            std::map<std::string, int> vRunResults = vSim.Run();
            
            for (const auto &vPair : vRunResults)
                vTotalTimes[vPair.first] += vPair.second;
        }
        
        std::cout << Cyan << "\n--- AVERAGE TRAVEL TIMES (" << vNbRuns << " RUNS) ---\n" << Reset_Color;
        for (const auto &vPair : vTotalTimes)
        {
            int vAverageTime = vPair.second / vNbRuns;
            std::cout << "- Train " << vPair.first << " : " << TimeUtils::MinToStr(vAverageTime) << "\n";
        }

        std::cout << Valid << Green << " Simulation completed successfully" << Reset_Color << std::endl;
    } 
    catch (const std::exception &e)
    {
        std::cerr << Deny << Red << " " << e.what() << Reset_Color << std::endl;
        return 1;
    }

    return 0;
}
