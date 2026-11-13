#pragma once

#include "IPathfinder.hpp"
#include <unordered_map>
#include <queue>

class DijkstraPathfinder : public IPathfinder 
{
	private :
		// Intern struct for priority of algo
		struct QueueElement
		{
			Node *mNode;
			double mDistance;

			bool operator>(const QueueElement &aOther) const {
				return mDistance > aOther.mDistance;
			}
		};

	public :
		DijkstraPathfinder() = default;
		~DijkstraPathfinder() override = default;

		std::vector<Rail *> CalculatePath(const Network &aNetwork, Node *aStart, Node *aEnd) override;
};
