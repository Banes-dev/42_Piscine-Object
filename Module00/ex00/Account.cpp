#include "Account.hpp"


// Constructor & Destructor
Account::Account(int aId) : mId(aId), mBalance(0)
{
}

Account::Account(int aId, double aBalance) : mId(aId), mBalance(aBalance)
{
}

Account::~Account()
{
}

// Others functions
int Account::GetId() const
{
	return mId;
}

double Account::GetBalance() const
{
	return mBalance;
}

double Account::GetLoan() const
{
	return mLoan;
}

std::ostream &operator<<(std::ostream& aOut, const Account &aAccount)
{
    aOut << "[" << aAccount.mId << "] - [" << aAccount.mBalance << "] - [" << aAccount.mLoan << "]";
    return (aOut);
}
