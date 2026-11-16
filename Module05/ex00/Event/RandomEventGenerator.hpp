#pragma once

#include <vector>
#include <string>

#include "IObserver.hpp"
#include "../Network/Network.hpp"


class RandomEventGenerator 
{
	private:
		std::vector<IObserver *> mObservers;
		int mTimeSinceLastEvent;
		int mNextEventCooldown;

	public:
		RandomEventGenerator();

		void AddObserver(IObserver *aObserver);
		void RemoveObserver(IObserver *aObserver);
		
		// Triggers random events in cities or on rails
		void Generate(const Network &aNetwork);
};
