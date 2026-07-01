#include "Account.hpp"


// Constructor & Destructor
Account::Account() : mId(aId), mBalance(0)
{
}

Account::Account(int aId, double aBalance) : mId(aId), mBalance(aBalance)
{
}

Account::~Account()
{
}

// Others functions
int GetId() const
{
	return mId;
}

double GetBalance() const
{
	return mBalance;
}

double GetLoan() const
{
	return mLoan;
}
