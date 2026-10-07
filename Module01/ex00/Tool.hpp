#pragma once

#include <iostream>

#include "Color.hpp"

class Worker;


enum ToolType {
    TOOL_GENERIC,
    TOOL_SHOVEL,
    TOOL_HAMMER
};

class Tool
{
	private :
		Worker *mWorker;
		ToolType mtype;

	protected :
		int mNbUse;

	public :
		// Constructor & Destructor
		Tool(ToolType aType  = TOOL_GENERIC);
		virtual ~Tool();

		// Others functions
		virtual void use() = 0;
		Worker *GetWorker();
		void SetWorker(Worker *aWorker);
		ToolType getType() const;
};
