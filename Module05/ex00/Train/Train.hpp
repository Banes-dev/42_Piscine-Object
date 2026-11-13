#pragma once

#include <string>
#include <vector>

#include "../Network/Rail.hpp"

class Train 
{
	private :
		std::string mName;
		double mWeight;          		// in metric ton
		double mFriction;        		// Coefficient de friction
		double mMaxAccel;        		// in kilonewtons (kN)
		double mMaxBrake;        		// in kilonewtons (kN)
		std::string mDepStation; 		// Start station
		std::string mArrStation; 		// End station
		int mDepTime;    				// Departure time
		int mStopDuration; 				// Stop duration

		std::vector<Rail *> mPath;
		size_t mCurrentRailIndex;
		double mCurrentSpeed;          	// km/h
		double mDistanceOnCurrentRail; 	// km
		bool mIsActive;
		bool mHasFinished;
		std::string mCurrentStateStr;  	// "Speed up", "Braking", "Maintain", "Stopped"

	public :
		Train(const std::string &aName, double aWeight, double aFriction, double aMaxAccel, double aMaxBrake, const std::string &aDepStation,
			const std::string &aArrStation,const int &aDepTime, const int &aStopDuration);

		void SetPath(const std::vector<Rail *> &aPath);
		const std::vector<Rail *> &GetPath() const;

		void UpdatePhysics(double aDeltaTimeMinutes); // Called every minute of the simulation

		void TryStart(int aCurrentTimeMinutes); // Check if the train should start based on current simulation time

		bool IsActive() const;
		bool HasFinished() const;

		void WriteTickLog(int aCurrentTimeMinutes) const; // Outputs the specific ASCII log format requested

		// Getters
		const std::string &GetName() const;
		double GetWeight() const;
		double GetFriction() const;
		double GetMaxAccel() const;
		double GetMaxBrake() const;
		const std::string &GetDepStation() const;
		const std::string &GetArrStation() const;
		const int &GetDepTime() const;
		const int &GetStopDuration() const;
};
