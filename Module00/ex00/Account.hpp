#pragma once

#include <iostream>
#include <string>

class Bank;

class Account
{
	private :
		unsigned int mId;
		double mBalance;
		double mLoan;
		
		// Constructor & Destructor
		Account(unsigned int aId, double aBalance);
		~Account();

		friend class Bank;

	public :
		// Others functions
		unsigned int GetId() const;
		double GetBalance() const;
		double GetLoan() const;

		friend std::ostream &operator << (std::ostream &aOut, const Account &aAccount);
};
