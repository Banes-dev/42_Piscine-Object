#pragma once

#include "Node.hpp"

class Rail 
{
	private :
		Node *mNodeA;
		Node *mNodeB;
		double mLength;
		double mMaxSpeed;

	public :
		Rail(Node *aNodeA, Node *aNodeB, double aLength, double aMaxSpeed);
		
		Node *GetNodeA() const;
		Node *GetNodeB() const;
		double GetLength() const;
		double GetMaxSpeed() const;
};