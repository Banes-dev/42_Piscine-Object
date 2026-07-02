#pragma once

#include <iostream>
#include <string>

class Bank;

class Account
{
	private :
		int mId;
		double mBalance;
		double mLoan;
		
		// Constructor & Destructor
		Account(int aId);
		Account(int aId, double aBalance);
		~Account();

		friend class Bank;

	public :
		// Others functions
		int GetId() const;
		double GetBalance() const;
		double GetLoan() const;

		friend std::ostream &operator << (std::ostream &aOut, const Account &aAccount);
};
