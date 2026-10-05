#include "Hammer.hpp"

// Constructor & Destructor
Hammer::Hammer() : Tool(TOOL_HAMMER)
{
	std::cout << Green << "[Hammer] " << Reset_Color << "Create a hammer" << std::endl;
}

Hammer::~Hammer()
{
	std::cout << Red << "[Hammer] " << Reset_Color << "Destroy a hammer" << std::endl;
}

// Others functions
void Hammer::use()
{
	this->mNbUse++;
	std::cout << "\033[0;32m[Hammer]\033[0m Hammer in a nail " << this->mNbUse << " times" << std::endl;
}
