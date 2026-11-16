#include "RandomEventGenerator.hpp"

#include <random>
#include <iostream>
#include <algorithm>


RandomEventGenerator::RandomEventGenerator() : mTimeSinceLastEvent(0), mNextEventCooldown(30)
{
}

void RandomEventGenerator::AddObserver(IObserver *aObserver)
{
    mObservers.push_back(aObserver);
}

void RandomEventGenerator::RemoveObserver(IObserver *aObserver)
{
    auto vIt = std::find(mObservers.begin(), mObservers.end(), aObserver);
    if (vIt != mObservers.end())
        mObservers.erase(vIt);
}

void RandomEventGenerator::Generate(const Network &aNetwork)
{
    mTimeSinceLastEvent++;
    if (mTimeSinceLastEvent < mNextEventCooldown)
        return;
    mTimeSinceLastEvent = 0;
    
    // Modern C++20 Random Generation
    std::random_device vDev;
    std::mt19937 vRng(vDev());
    std::uniform_int_distribution<std::mt19937::result_type> vCooldownDist(30, 120); // 30 to 120 mins before next event
    std::uniform_int_distribution<std::mt19937::result_type> vDurationDist(10, 45);  // Delay duration
    
    mNextEventCooldown = vCooldownDist(vRng);

    const auto &vRails = aNetwork.GetRails();
    if (vRails.empty())
        return;

    // Pick a random rail to trigger an event
    std::uniform_int_distribution<std::mt19937::result_type> vRailDist(0, vRails.size() - 1);
    Rail *vTargetRail = vRails[vRailDist(vRng)].get();
    
    // The event happens at the starting node of the selected rail
    std::string vLocation = vTargetRail->GetNodeA()->GetName();
    std::string vEventType = "Weather Hazard";
    int vDuration = vDurationDist(vRng);

    // Notify all subscribed trains
    for (IObserver *vObserver : mObservers)
        vObserver->OnEvent(vLocation, vEventType, vDuration);
}
