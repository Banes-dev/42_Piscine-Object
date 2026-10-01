#pragma once

#include "Tool.hpp"

class Shovel : public Tool
{
	public :
		// Constructor & Destructor
		Shovel();
		~Shovel();

		// Others functions
		void use(float aX, float aY) const;
}
