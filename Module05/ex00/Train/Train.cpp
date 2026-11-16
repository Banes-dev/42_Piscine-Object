#include "Train.hpp"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "../Simulation/TimeUtils.hpp"


Train::Train(const std::string &aName, double aWeight, double aFriction, double aMaxAccel, double aMaxBrake,
	const std::string &aDepStation,const std::string &aArrStation, int aDepTime, int aStopDuration)
    : mName(aName), mWeight(aWeight), mFriction(aFriction), mMaxAccel(aMaxAccel), mMaxBrake(aMaxBrake), mDepStation(aDepStation), mArrStation(aArrStation),mDepTime(aDepTime),
	mStopDuration(aStopDuration),mCurrentRailIndex(0), mCurrentSpeed(0.0), mDistanceOnCurrentRail(0.0),mIsActive(false), mHasFinished(false), mCurrentStateStr("Stopped"),
	mDistanceToObstacle(-1.0), mBlockingTrainCell(-1), mEventDelayTimer(0), mActualTravelTime(0)
{
}

Train::~Train()
{
    if (mLogFile.is_open())
        mLogFile.close();
}

void Train::InitLogFile()
{
    std::string vFilename = mName + "_" + TimeUtils::MinToStr(mDepTime) + ".result";

    mLogFile.open(vFilename);
    if (!mLogFile.is_open())
        throw std::runtime_error("Cannot create log file for train : " + mName);

    // Basic time estimation (Total distance / Max Speed constraint)
    double vTotalDist = 0.0;
    for (Rail *vRail : mPath)
        vTotalDist += vRail->GetLength();

    // Very rough estimation in minutes (assuming average speed around 150km/h)
    int vEstimatedMinutes = static_cast<int>((vTotalDist / 150.0) * 60.0);

    mLogFile << "Train : " << mName << "\n";
    mLogFile << "Final travel time : " << TimeUtils::MinToStr(vEstimatedMinutes) << "m\n\n";
}

void Train::SetPath(const std::vector<Rail *> &aPath)
{
    mPath = aPath;
}

const std::vector<Rail *> &Train::GetPath() const
{
    return mPath;
}

size_t Train::GetCurrentRailIndex() const
{
    return mCurrentRailIndex;
}

double Train::GetDistanceOnCurrentRail() const
{
    return mDistanceOnCurrentRail;
}

void Train::DetectObstacles(const std::vector<std::unique_ptr<Train>> &aAllTrains)
{
    mDistanceToObstacle = -1.0;
    mBlockingTrainCell = -1;

    if (!mIsActive || mHasFinished || mPath.empty())
        return;

    Rail *vCurrentRail = mPath[mCurrentRailIndex];

    for (const auto &vOtherTrainPtr : aAllTrains)
    {
        Train *vOther = vOtherTrainPtr.get();

        if (vOther == this || !vOther->IsActive() || vOther->HasFinished() || vOther->GetPath().empty())
            continue;

        // Check if the other train is on the exact same rail
        if (vCurrentRail == vOther->GetPath()[vOther->GetCurrentRailIndex()])
        {
            // If the other train is ahead of us
            if (vOther->GetDistanceOnCurrentRail() > mDistanceOnCurrentRail)
            {
                double vDistBetweenKm = vOther->GetDistanceOnCurrentRail() - mDistanceOnCurrentRail;

                // Keep the closest obstacle
                if (mDistanceToObstacle < 0.0 || vDistBetweenKm < mDistanceToObstacle)
                {
                    mDistanceToObstacle = vDistBetweenKm;
                    mBlockingTrainCell = static_cast<int>(vOther->GetDistanceOnCurrentRail());
                }
            }
        }
    }
}

bool Train::IsActive() const
{
    return mIsActive;
}

bool Train::HasFinished() const
{
    return mHasFinished;
}

void Train::TryStart(int aCurrentTimeMinutes)
{
    if (aCurrentTimeMinutes >= mDepTime && !mHasFinished)
    {
        mIsActive = true;
        mCurrentStateStr = "Speed up";
		InitLogFile();
    }
}

void Train::UpdatePhysics(double aDeltaTimeMinutes)
{
    if (!mIsActive || mHasFinished || mPath.empty()) {
        return;
	}

	mActualTravelTime++;

	// Check if the train is currently at the location of the event
    if (mEventDelayTimer > 0)
    {
        mEventDelayTimer--;
        mCurrentSpeed = 0.0;
        return;
    }

    // Convert delta time to seconds (1 minute = 60 seconds)
    double vDeltaTimeSec = aDeltaTimeMinutes * 60.0;

    // Convert physics properties to standard SI units (kg, Newtons, m/s)
    double vMassKg = mWeight * 1000.0;
    double vFrictionForce = mFriction * vMassKg * 9.81; // F = mu * m * g
    double vMaxAccelForce = mMaxAccel * 1000.0;
    double vMaxBrakeForce = mMaxBrake * 1000.0;
    double vCurrentSpeedMs = mCurrentSpeed / 3.6;
    
    Rail *vCurrentRail = mPath[mCurrentRailIndex];
    double vRailMaxSpeedMs = vCurrentRail->GetMaxSpeed() / 3.6;

    // Calculate total remaining distance on the whole path
    double vTotalDistanceLeftMeters = (vCurrentRail->GetLength() - mDistanceOnCurrentRail) * 1000.0;
    for (size_t i = mCurrentRailIndex + 1; i < mPath.size(); ++i)
        vTotalDistanceLeftMeters += (mPath[i]->GetLength() * 1000.0);

	// Integrate collision avoidance
    double vTargetDistanceMeters = vTotalDistanceLeftMeters;
    if (mDistanceToObstacle >= 0.0)
    {
        // Safe margin of 50 meters behind the train ahead
        double vObstacleDistMeters = (mDistanceToObstacle * 1000.0) - 50.0;
        if (vObstacleDistMeters < vTargetDistanceMeters)
            vTargetDistanceMeters = vObstacleDistMeters;
        
        if (vTargetDistanceMeters < 0.0)
            vTargetDistanceMeters = 0.0;
    }

    // Calculate maximum deceleration capacity (a = F/m)
    double vDecelerationMs2 = (vMaxBrakeForce + vFrictionForce) / vMassKg;

    // Calculate required distance to stop at current speed (d = v^2 / 2a)
    double vBrakingDistanceMeters = (vCurrentSpeedMs * vCurrentSpeedMs) / (2.0 * vDecelerationMs2);

    // Decision tree for the train state
	double vCurrentAccelMs2 = 0.0;
    if (vTargetDistanceMeters <= vBrakingDistanceMeters)
    {
        mCurrentStateStr = "Braking";
        vCurrentAccelMs2 = -vDecelerationMs2;
    }
    else if (vCurrentSpeedMs < vRailMaxSpeedMs)
    {
        mCurrentStateStr = "Speed up";
        vCurrentAccelMs2 = (vMaxAccelForce - vFrictionForce) / vMassKg;
        
        // Prevent negative acceleration if friction is stronger than max engine force
        if (vCurrentAccelMs2 < 0.0)
            vCurrentAccelMs2 = 0.0;
    }
    else
    {
        mCurrentStateStr = "Maintain";
        vCurrentAccelMs2 = 0.0;
        vCurrentSpeedMs = vRailMaxSpeedMs; // Cap at max rail speed
    }

    // Apply acceleration to speed (v = v0 + at)
    double vNewSpeedMs = vCurrentSpeedMs + (vCurrentAccelMs2 * vDeltaTimeSec);

    // Speed limits safeguards
    if (vNewSpeedMs < 0.0)
        vNewSpeedMs = 0.0;
    if (mCurrentStateStr == "Speed up" && vNewSpeedMs > vRailMaxSpeedMs)
    {
        vNewSpeedMs = vRailMaxSpeedMs;
        mCurrentStateStr = "Maintain";
    }

    // Calculate distance covered during this tick using average speed
    double vAvgSpeedMs = (vCurrentSpeedMs + vNewSpeedMs) / 2.0;
    double vDistanceCoveredKm = (vAvgSpeedMs * vDeltaTimeSec) / 1000.0;

    // Update state variables
    mCurrentSpeed = vNewSpeedMs * 3.6; // Convert back to km/h
    mDistanceOnCurrentRail += vDistanceCoveredKm;

    // Check if the train arrived at the final destination
    if (mCurrentSpeed == 0.0 && vTotalDistanceLeftMeters <= ((vDistanceCoveredKm * 1000.0) + 10.0)) // 10m margin of error
    {
        mCurrentStateStr = "Stopped";
        mHasFinished = true;
        mIsActive = false;
        return;
    }

    // Advance to next rails if the train crossed the current one
    while (mCurrentRailIndex < mPath.size() && mDistanceOnCurrentRail >= mPath[mCurrentRailIndex]->GetLength())
    {
        mDistanceOnCurrentRail -= mPath[mCurrentRailIndex]->GetLength();
        mCurrentRailIndex++;
    }

    // Stop safely if we accidentally overshot the last rail
    if (mCurrentRailIndex >= mPath.size())
    {
        mCurrentRailIndex = mPath.size() - 1;
        mDistanceOnCurrentRail = mPath[mCurrentRailIndex]->GetLength();
        mHasFinished = true;
        mIsActive = false;
        mCurrentStateStr = "Stopped";
        mCurrentSpeed = 0.0;
    }
}

void Train::WriteTickLog(int aCurrentTimeMinutes)
{
    if (!mLogFile.is_open() || mPath.empty())
        return;

    // Calculate total remaining distance
    double vTotalDistanceLeftKm = mPath[mCurrentRailIndex]->GetLength() - mDistanceOnCurrentRail;
    for (size_t i = mCurrentRailIndex + 1; i < mPath.size(); ++i)
        vTotalDistanceLeftKm += mPath[i]->GetLength();

    if (vTotalDistanceLeftKm < 0.0)
        vTotalDistanceLeftKm = 0.0;

    Rail *vCurrentRail = mPath[mCurrentRailIndex];

	// Build the ASCII graph (one cell per km)
    int vTotalCells = static_cast<int>(vCurrentRail->GetLength());
    if (vTotalCells < 1) 
        vTotalCells = 1;
        
    int vCurrentCell = static_cast<int>(mDistanceOnCurrentRail);
    if (vCurrentCell >= vTotalCells)
        vCurrentCell = vTotalCells - 1;

    std::string vGraph = "";
    for (int i = 0; i < vTotalCells; ++i)
    {
        if (i == vCurrentCell)
            vGraph += "[x]";
        else if (i == mBlockingTrainCell) // Draw blocking train
            vGraph += "[O]";
        else
            vGraph += "[]";
    }

    mLogFile << "[" << TimeUtils::MinToStr(aCurrentTimeMinutes) << "] " << "[" << std::setw(10) << vCurrentRail->GetNodeA()->GetName() << "] "
		<< "[" << std::setw(10) << vCurrentRail->GetNodeB()->GetName() << "]\n" << "[" << std::fixed << std::setprecision(2) << std::setw(5) << std::setfill('0')
		<< vTotalDistanceLeftKm << "km]\n" << "[" << std::setw(10) << std::setfill(' ') << mCurrentStateStr << "]\n" << vGraph << "\n\n";
}

void Train::OnEvent(const std::string &aLocationName, const std::string &aEventType, int aDurationMinutes)
{
    if (!mIsActive || mHasFinished || mPath.empty())
        return;
    
    // If the train is currently at the location of the event
    if (mPath[mCurrentRailIndex]->GetNodeA()->GetName() == aLocationName)
    {
        mEventDelayTimer = aDurationMinutes;
        mCurrentStateStr = aEventType;
    }
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

const int &Train::GetActualTravelTime() const
{
	return mActualTravelTime;
}
