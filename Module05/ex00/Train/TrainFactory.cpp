#include "TrainFactory.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <set>

#include "../Simulation/TimeUtils.hpp"


std::vector<std::unique_ptr<Train>> TrainFactory::BuildTrains(const std::string &aFilename)
{
    std::vector<std::unique_ptr<Train>> vTrains;
    std::ifstream vFile(aFilename);

    if (!vFile.is_open())
        throw std::runtime_error("Could not open train file : " + aFilename);

    std::string vLine;
    std::set<std::string> vNames;
    unsigned int vId = 1;
    while (std::getline(vFile, vLine))
    {
        if (vLine.empty() || vLine[0] == '#')
            continue;

        std::istringstream vStream(vLine);
        
        std::string vName, vDepStation, vArrStation, vDepTimeStr, vStopDurationStr;
        double vWeight, vFriction, vMaxAccel, vMaxBrake;

        // Syntax : Name Weight Friction MaxAccel MaxBrake DepStation ArrStation DepTime StopDuration
        if (!(vStream >> vName >> vWeight >> vFriction >> vMaxAccel >> vMaxBrake >> vDepStation >> vArrStation >> vDepTimeStr >> vStopDurationStr) || !vStream.eof())
            throw std::runtime_error("Invalid Train syntax : " + vLine);
        if (!vNames.insert(vName).second)
            throw std::runtime_error("Duplicate train name : " + vName);
        if (!std::isfinite(vWeight) || !std::isfinite(vFriction)
            || !std::isfinite(vMaxAccel) || !std::isfinite(vMaxBrake)
            || vWeight <= 0.0 || vFriction < 0.0 || vMaxAccel <= 0.0 || vMaxBrake <= 0.0)
            throw std::runtime_error("Invalid train values : " + vLine);

		// Convert to min from midnight
		int vDepTime = TimeUtils::StrToMin(vDepTimeStr);
		int vStopDuration = TimeUtils::StrToMin(vStopDurationStr);

		vTrains.push_back(std::make_unique<Train>(vId++, vName, vWeight, vFriction, vMaxAccel, vMaxBrake, vDepStation, vArrStation, vDepTime, vStopDuration));
    }

    return vTrains;
}
