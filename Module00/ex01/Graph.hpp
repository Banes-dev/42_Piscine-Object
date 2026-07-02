#pragma once

#include <iostream>
#include <string>

class Vector2;

class Graph
{
	private :
		Vector2 mSize;
		std::list<Vector2 *> mPoints;

	public :
		// Constructor & Destructor
		Graph(unsigned int aId, double aBalance);
		~Graph();

		// Others functions
		void CreatePoint(unsigned int aX, unsigned int aY);
		// unsigned int GetId() const;
		// double GetBalance() const;
		// double GetLoan() const;

		friend std::ostream &operator << (std::ostream &aOut, const Graph &aGraph);
};
