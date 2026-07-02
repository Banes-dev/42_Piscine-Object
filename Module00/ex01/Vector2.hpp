#pragma once

#include <iostream>
#include <string>

class Bank;

class Vector2
{
	private :
		unsigned int mX;
		unsigned int mY;

	public :
		// Constructor & Destructor
		Vector2(unsigned int aId, double aBalance);
		~Vector2();

		// Others functions
		// unsigned int GetId() const;
		// double GetBalance() const;
		// double GetLoan() const;

		friend std::ostream &operator << (std::ostream &aOut, const Vector2 &aVector2);
};
