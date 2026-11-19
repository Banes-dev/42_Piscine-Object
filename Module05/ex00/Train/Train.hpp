#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "../Network/Rail.hpp"
#include "../Event/IObserver.hpp"

class Train : public IObserver
{
	private :
		std::string mName;
		unsigned int mId;
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

		double mDistanceToObstacle; 	// In km (-1.0 if no obstacle)
		int mBlockingTrainCell;     	// Index for the 'O' in the ASCII graph

		std::ofstream mLogFile;
		void InitLogFile();
		Node *GetCurrentStartNode() const;
		Node *GetCurrentEndNode() const;

		int mEventDelayTimer;
		int mStationStopTimer;

		int mActualTravelTime;

	public :
		Train(unsigned int aId, const std::string &aName, double aWeight, double aFriction, double aMaxAccel, double aMaxBrake,
			const std::string &aDepStation, const std::string &aArrStation, int aDepTime, int aStopDuration);

		~Train();

		void SetPath(const std::vector<Rail *> &aPath);
		const std::vector<Rail *> &GetPath() const;

		size_t GetCurrentRailIndex() const;
		double GetDistanceOnCurrentRail() const;
		void DetectObstacles(const std::vector<std::unique_ptr<Train>> &aAllTrains);

		void UpdatePhysics(double aDeltaTimeMinutes);
		void TryStart(int aCurrentTimeMinutes);
		bool IsActive() const;
		bool HasFinished() const;
		void WriteTickLog(int aCurrentTimeMinutes);

		void OnEvent(const std::string &aLocationName, const std::string &aEventType, int aDurationMinutes) override;

		// Getters
		const std::string &GetName() const;
		unsigned int GetId() const;
		double GetWeight() const;
		double GetFriction() const;
		double GetMaxAccel() const;
		double GetMaxBrake() const;
		const std::string &GetDepStation() const;
		const std::string &GetArrStation() const;
		const int &GetDepTime() const;
		const int &GetStopDuration() const;
		const int &GetActualTravelTime() const;
};
