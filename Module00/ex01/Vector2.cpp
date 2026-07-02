#include "Vector2.hpp"


// Constructor & Destructor
Vector2::Vector2(unsigned int aId, double aBalance) : mId(aId), mBalance(aBalance)
{
}

Vector2::~Vector2()
{
}

// Others functions
unsigned int Vector2::GetId() const
{
	return mId;
}

double Vector2::GetBalance() const
{
	return mBalance;
}

double Vector2::GetLoan() const
{
	return mLoan;
}

std::ostream &operator<<(std::ostream& aOut, const Vector2 &aVector2)
{
    aOut << "[" << aVector2.mId << "] - [" << aVector2.mBalance << "] - [" << aVector2.mLoan << "]";
    return (aOut);
}
