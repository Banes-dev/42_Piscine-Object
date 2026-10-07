#pragma once

#include <iostream>
#include <vector>

#include "Color.hpp"
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
		void ExecuteWorkDay();
		ToolType GetToolRequired() const;

		// Exceptions
		class WorkerNotExistException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mWorker not exist\033[0m");}
		};
		class WorkerHasNoToolException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mWorker has no tool\033[0m");}
		};
};
