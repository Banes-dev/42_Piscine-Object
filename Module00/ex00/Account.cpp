#include "Account.hpp"


// Constructor & Destructor
Account::Account(unsigned int aId, double aBalance) : mId(aId), mBalance(aBalance)
{
}

Account::~Account()
{
}

// Others functions
unsigned int Account::GetId() const
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
