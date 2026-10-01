#pragma once

#include "Tool.hpp"

class Hammer : public Tool
{
	public :
		// Constructor & Destructor
		Hammer();
		~Hammer();

		// Others functions
		void use(float aX, float aY) const;
}
