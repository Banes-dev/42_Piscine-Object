#pragma once

#include <iostream>
#include <string>

#include "Bank.hpp"

class Bank;

class Account
{
	private :
		int mId;
		double mBalance;
		double mLoan;
		
		// Constructor & Destructor
		Account();
		Account(int aId, double aBalance);
		~Account();

		friend class Bank;

	public :
		// Others functions
		int GetId() const;
		double GetBalance() const;
		double GetLoan() const;

}
