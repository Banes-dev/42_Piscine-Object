#pragma once

#include <iostream>

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Worker
{
	private :
		Position mPos;
		Statistic mStat;

	public :
		// Constructor & Destructor
		Worker(Position aPos, Statistic aStat);
		~Worker();

		// Others functions
		Tool GetTool<ToolType>();
		void AddTool(Tool *aTool);
		void RemoveTool(Tool *aTool);

		// Exceptions
		class NumberMustBePositive : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mNumber must be positive\033[0m");}
		};
}
