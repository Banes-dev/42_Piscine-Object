#pragma once

#include "Color.hpp"
#include "Tool.hpp"


class Shovel : public Tool
{
	public :
		// Constructor & Destructor
		Shovel();
		virtual ~Shovel();

		// Others functions
		virtual void use();
};
