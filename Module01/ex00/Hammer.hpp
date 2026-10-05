#pragma once

#include "Color.hpp"
#include "Tool.hpp"

class Hammer : public Tool
{
	public :
		// Constructor & Destructor
		Hammer();
		virtual ~Hammer();

		// Others functions
		virtual void use();
};
