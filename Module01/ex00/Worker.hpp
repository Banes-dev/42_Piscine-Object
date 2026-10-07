#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

#include "Color.hpp"
#include "Tool.hpp"

class Workshop;

struct Position {
	int x;
	int y;
	int z;
};

struct Statistic {
	int level;
	int exp;
};

class Worker
{
	private :
		Position mPos;
		Statistic mStat;
		std::vector<Tool *> mTools;
		std::vector<Workshop *> mWorkshops;

	public :
		// Constructor & Destructor
		Worker(Position aPos, Statistic aStat);
		~Worker();

		// Others functions
		template <typename T>
		T *GetTool() const
		{
			for (size_t i = 0; i < mTools.size(); ++i)
			{
				T *specificTool = dynamic_cast<T*>(mTools[i]);
				if (specificTool != NULL)
					return specificTool;
			}
			return NULL;
		}
		void AddTool(Tool *aTool);
		void RemoveTool(Tool *aTool);
		void Work();
		bool HasToolType(ToolType aType) const;
		void AddWorkshop(Workshop *aWorkshop);
		void RemoveWorkshop(Workshop *aWorkshop);

		// Exceptions
		class ToolNotExistException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mTool not exist\033[0m");}
		};
		class WorkshopNotExistException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mWorkshop not exist\033[0m");}
		};
};
