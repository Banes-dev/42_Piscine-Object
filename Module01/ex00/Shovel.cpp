#include "Shovel.hpp"

// Constructor & Destructor
Shovel::Shovel() : Tool(TOOL_SHOVEL)
{
	std::cout << Green << "[Shovel] " << Reset_Color << "Create a shovel" << std::endl;
}

Shovel::~Shovel()
{
	std::cout << Red << "[Shovel] " << Reset_Color << "Destroy a shovel" << std::endl;
}

// Others functions
void Shovel::use()
{
	this->mNbUse++;
	std::cout << "\033[0;32m[Shovel]\033[0m Dig a hole " << this->mNbUse << " times" << std::endl;
}
