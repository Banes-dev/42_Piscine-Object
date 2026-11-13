#include "TimeUtils.hpp"

#include <stdexcept>
#include <iomanip>
#include <sstream>


int TimeUtils::StrToMin(const std::string &aTimeStr)
{
    size_t vPos = aTimeStr.find('h');

    if (vPos == std::string::npos)
        throw std::runtime_error("Invalid time format (missing 'h') : " + aTimeStr);

    try
    {
        int vHours = std::stoi(aTimeStr.substr(0, vPos));
        int vMinutes = std::stoi(aTimeStr.substr(vPos + 1));

        return (vHours * 60) + vMinutes;
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Invalid time numbers in : " + aTimeStr);
    }
}

std::string TimeUtils::MinToStr(int aMinutes)
{
    // % 24 resets to 00:00 past midnight
    int vHours = (aMinutes / 60) % 24;
    int vMins = aMinutes % 60;

    std::ostringstream vStream;
    vStream << std::setw(2) << std::setfill('0') << vHours << "h" << std::setw(2) << std::setfill('0') << vMins;
    
    return vStream.str();
}
