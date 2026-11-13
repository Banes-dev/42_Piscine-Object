#include "TrainFactory.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "../Simulation/TimeUtils.hpp"


std::vector<std::unique_ptr<Train>> TrainFactory::BuildTrains(const std::string &aFilename)
{
    std::vector<std::unique_ptr<Train>> vTrains;
    std::ifstream vFile(aFilename);

    if (!vFile.is_open())
        throw std::runtime_error("Could not open train file : " + aFilename);

    std::string vLine;
    while (std::getline(vFile, vLine))
    {
        if (vLine.empty())
            continue;

        std::istringstream vStream(vLine);
        
        std::string vName, vDepStation, vArrStation, vDepTimeStr, vStopDurationStr;
        double vWeight, vFriction, vMaxAccel, vMaxBrake;

        // Syntax : Name Weight Friction MaxAccel MaxBrake DepStation ArrStation DepTime StopDuration
        if (!(vStream >> vName >> vWeight >> vFriction >> vMaxAccel >> vMaxBrake >> vDepStation >> vArrStation >> vDepTimeStr >> vStopDurationStr) || !vStream.eof())
            throw std::runtime_error("Invalid Train syntax : " + vLine);

		// Convert to min from midnight
		int vDepTime = TimeUtils::StrToMin(vDepTimeStr);
		int vStopDuration = TimeUtils::StrToMin(vStopDurationStr);

		vTrains.push_back(std::make_unique<Train>(vName, vWeight, vFriction, vMaxAccel, vMaxBrake, vDepStation, vArrStation, vDepTime, vStopDuration));
    }

    return vTrains;
}
