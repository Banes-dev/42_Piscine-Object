#include "Train.hpp"


Train::Train(const std::string &aName, double aWeight, double aFriction, double aMaxAccel, double aMaxBrake, const std::string &aDepStation,
	const std::string &aArrStation, const int &aDepTime, const int &aStopDuration)
    : mName(aName), mWeight(aWeight), mFriction(aFriction), mMaxAccel(aMaxAccel), mMaxBrake(aMaxBrake), mDepStation(aDepStation), mArrStation(aArrStation), mDepTime(aDepTime), mStopDuration(aStopDuration)
{
}



// Getters
const std::string &Train::GetName() const
{
    return mName;
}

double Train::GetWeight() const
{
    return mWeight;
}

double Train::GetFriction() const
{
    return mFriction;
}

double Train::GetMaxAccel() const
{
    return mMaxAccel;
}

double Train::GetMaxBrake() const
{
    return mMaxBrake;
}

const std::string &Train::GetDepStation() const
{
    return mDepStation;
}

const std::string &Train::GetArrStation() const
{
    return mArrStation;
}

const int &Train::GetDepTime() const
{
    return mDepTime;
}

const int &Train::GetStopDuration() const
{
    return mStopDuration;
}
