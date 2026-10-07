#include "Workshop.hpp"

// Constructor & Destructor
Workshop::Workshop(ToolType aToolRequired) : mToolRequired(aToolRequired)
{
	std::cout << Green << "[Workshop] " << Reset_Color << "Create a workshop" << std::endl;
}
Workshop::~Workshop()
{
	std::cout << Red << "[Workshop] " << Reset_Color << "Destroy a workshop" << std::endl;
}

// Others functions
void Workshop::AddWorker(Worker *aWorker)
{
	if (aWorker == NULL)
		throw WorkerNotExistException();

	// Check if the worker has the required tool
	if (aWorker->HasToolType(mToolRequired) == false)
		throw WorkerHasNoToolException();

	if (std::find(mWorkers.begin(), mWorkers.end(), aWorker) == mWorkers.end())
	{
		this->mWorkers.push_back(aWorker);
		aWorker->AddWorkshop(this);
		std::cout << Purple << "[Workshop] " << Reset_Color << "Add a worker" << std::endl;
	}
}

void Workshop::RemoveWorker(Worker *aWorker)
{
	if (aWorker == NULL)
		throw WorkerNotExistException();

	std::vector<Worker *>::iterator it = std::find(this->mWorkers.begin(), this->mWorkers.end(), aWorker);
	if (it != this->mWorkers.end())
	{
		this->mWorkers.erase(it);
		aWorker->RemoveWorkshop(this);
		std::cout << Purple << "[Workshop] " << Reset_Color << "Remove a worker" << std::endl;
	}
}

void Workshop::ExecuteWorkDay()
{
	std::vector<Worker *>::iterator it = this->mWorkers.begin();
	while (it != this->mWorkers.end())
	{
		Worker *worker = *it;
		worker->Work();
		++it;
	}
}

ToolType Workshop::GetToolRequired() const
{
	return mToolRequired;
}
