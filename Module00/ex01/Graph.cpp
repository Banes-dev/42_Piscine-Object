#include "Graph.hpp"


// Constructor & Destructor
Graph::Graph(unsigned int aId, double aBalance) : mId(aId), mBalance(aBalance)
{
}

Graph::~Graph()
{
}

// Others functions
unsigned int Graph::GetId() const
{
	return mId;
}

double Graph::GetBalance() const
{
	return mBalance;
}

double Graph::GetLoan() const
{
	return mLoan;
}

std::ostream &operator<<(std::ostream& aOut, const Graph &aGraph)
{
    aOut << "[" << aGraph.mId << "] - [" << aGraph.mBalance << "] - [" << aGraph.mLoan << "]";
    return (aOut);
}
