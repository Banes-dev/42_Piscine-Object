#pragma once

#include <vector>

#include "../Network/Network.hpp"
#include "../Network/Rail.hpp"
#include "../Network/Node.hpp"

class IPathfinder 
{
	public :
		virtual ~IPathfinder() = default;

		virtual std::vector<Rail *> CalculatePath(const Network &aNetwork, Node *aStart, Node *aEnd) = 0;
};
