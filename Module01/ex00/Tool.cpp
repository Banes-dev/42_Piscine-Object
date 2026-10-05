#include "Tool.hpp"

// Constructor & Destructor
Tool::Tool(ToolType aType) : mNbUse(0), mWorker(NULL), mtype(aType)
{
	std::cout << Green << "[Tool] " << Reset_Color << "Create a tool of type " << Yellow << aType << Reset_Color << std::endl;
}

Tool::~Tool()
{
	std::cout << Red << "[Tool] " << Reset_Color << "Destroy a tool of type " << Yellow << this->mtype << Reset_Color << std::endl;
}

// Others functions
Worker *Tool::GetWorker()
{
	return this->mWorker;
}

void Tool::SetWorker(Worker *aWorker)
{
	this->mWorker = aWorker;
}

ToolType Tool::getType() const
{
	return this->mtype;
}

