#pragma once

#include <iostream>
#include <vector>

#include "Worker.hpp"
#include "Tool.hpp"

class Workshop
{
	private :
		std::vector<Worker *> mWorkers;
		ToolType mToolRequired;

	public :
		// Constructor & Destructor
		Workshop(ToolType aToolRequired);
		~Workshop();

		// Others functions
		void AddWorker(Worker *aWorker);
		void RemoveWorker(Worker *aWorker);

		void Work();
		void ExecuteWorkDay();

		// Exceptions
		class NumberMustBePositive : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mNumber must be positive\033[0m");}
		};
};
