#pragma once

#include "Worker.hpp"

class Tool
{
	private :
		int mNbUse;
		Worker *mWorker;

	public :
		// Constructor & Destructor
		Tool();
		virtual ~Tool();

		// Others functions
		virutal void use(float aX, float aY) const = 0;
		Worker *GetWorker();
		void SetWorker(Worker *aWorker);
}
