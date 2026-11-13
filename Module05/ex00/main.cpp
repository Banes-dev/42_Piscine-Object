#include <iostream>

#include "Color.hpp"
#include "Simulation/Simulation.hpp"

int main(int aArgc, char **aArgv)
{
	// Check args
	if (aArgc != 3)
	{
		std::cerr << Deny << Red << " Error wrong args\n" << Yellow << "Try : ./Train_Yourself [file].rail [file].train" << Reset_Color << std::endl;
		return 1;
	}

	// Parse info file & launch the simulation
	try
    {
        std::string vRailFile = aArgv[1];
        std::string vTrainFile = aArgv[2];

        Simulation vSim;
        vSim.LoadNetwork(vRailFile);
        vSim.LoadTrains(vTrainFile);
        
        vSim.Run();
        
        std::cout << Valid << Green << " Simulation completed successfully" << Reset_Color << std::endl;
    } 
    catch (const std::exception &e)
    {
        std::cerr << Deny << Red << e.what() << Reset_Color << std::endl;
        return 1;
    }

    return 0;
}
