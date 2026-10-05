#include "Worker.hpp"
#include "Color.hpp"

// Constructor & Destructor
Worker::Worker(Position aPos, Statistic aStat) : mPos(aPos), mStat(aStat)
{
	std::cout << Green << "[Worker] " << Reset_Color << "Create a worker" << std::endl;
}

Worker::~Worker()
{
	// Remove the link between workers and tools
	for (size_t i = 0; i < this->mTools.size(); ++i)
		this->mTools[i]->SetWorker(NULL);
	this->mTools.clear();

	// Remove workers of workshops
	for (size_t i = 0; i < this->mWorkshops.size(); ++i)
		this->mWorkshops[i]->RemoveWorker(this);
	this->mWorkshops.clear();
	std::cout << Red << "[Worker] " << Reset_Color << "Destroy a worker" << std::endl;
}

// Others functions
void Worker::AddTool(Tool *aTool)
{
	if (aTool == NULL)
		throw ToolNotExistException();

	// Check if the tool is already attached to a worker
	if (aTool->GetWorker() != NULL && aTool->GetWorker() != this)
		aTool->GetWorker()->RemoveTool(aTool);
		
	// Add the tool to the list of tools and set the worker
	if (std::find(mTools.begin(), mTools.end(), aTool) == mTools.end())
	{
		this->mTools.push_back(aTool);
		aTool->SetWorker(this);
		std::cout << Cyan << "[Worker] " << Reset_Color << "Add a tool of type " << Yellow << aTool->getType() << Reset_Color << std::endl;
	}
}

void Worker::RemoveTool(Tool *aTool)
{
	if (aTool == NULL)
		throw ToolNotExistException();

	std::vector<Tool *>::iterator it = std::find(this->mTools.begin(), this->mTools.end(), aTool);
	if (it != this->mTools.end())
	{
		this->mTools.erase(it);
		aTool->SetWorker(NULL);
		std::cout << Cyan << "[Worker] " << Reset_Color << "Remove a tool of type " << Yellow << aTool->getType() << Reset_Color << std::endl;
		
	}
}
