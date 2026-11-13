#include "NetworkFactory.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>


Network NetworkFactory::BuildNetwork(const std::string &aFilename)
{
    Network vNetwork;
    std::ifstream vFile(aFilename);

    if (!vFile.is_open())
        throw std::runtime_error("Could not open network file: " + aFilename);

    std::string vLine;
    while (std::getline(vFile, vLine))
    {
        if (vLine.empty())
            continue;

        std::istringstream vStream(vLine);
        std::string vType;
        vStream >> vType;

        if (vType == "Node")
            ParseNode(vNetwork, vLine);
        else if (vType == "Rail")
            ParseRail(vNetwork, vLine);
        else
            throw std::runtime_error("Invalid identifier in rail file : " + vType);
    }

    return vNetwork;
}

void NetworkFactory::ParseNode(Network &aNetwork, const std::string &aLine)
{
    std::istringstream vStream(aLine);
    std::string vType, vName;

    // Syntax = Node Name
    if (!(vStream >> vType >> vName) || !vStream.eof())
        throw std::runtime_error("Invalid Node syntax : " + aLine);

    aNetwork.AddNode(vName);
}

void NetworkFactory::ParseRail(Network &aNetwork, const std::string &aLine)
{
    std::istringstream vStream(aLine);
    std::string vType, vCityA, vCityB;
    double vLength, vMaxSpeed;

    // Syntax = Rail CityA CityB Length MaxSpeed
    if (!(vStream >> vType >> vCityA >> vCityB >> vLength >> vMaxSpeed) || !vStream.eof())
        throw std::runtime_error("Invalid Rail syntax: " + aLine);

    aNetwork.AddRail(vCityA, vCityB, vLength, vMaxSpeed);
}
