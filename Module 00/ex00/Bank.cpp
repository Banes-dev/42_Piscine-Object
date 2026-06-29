#include "Bank.hpp"

// Constructor & Destructor
Bank::Bank() : mLiquidity(0)
{
}
Bank::Bank(int aLiquidity) : mLiquidity(aLiquidity)
{
}

Bank::~Bank()
{
}


// Others functions
void SetLiquidity(int aLiquidy)
{
	mLiquidity = aLiquidity;
}
int GetLiquidity()
{
	return mLiquidity;
}

Account CreateAccount()
{
}
void DeleteAccount(Account *aAccount)
{
}

void DepositMoney(Account *aAccount, int aMoney)
{
}
void WithdrawMoney(Account *aAccount, int aMoney)
{
}
void GiveLoan(Account *aAccount, int aMoney)
{
}

std::ostream &operator <<(std::ostream &aOutput, const Bank &aBank)
{
	aOutput << "Bank informations : " << std::endl;
	aOutput << "Liquidity : " << aBank.liquidity << std::endl;
	for (auto &clientAccount : aBank.clientAccounts)
    aOutput << *clientAccount << std::endl;
	return (aOutput);
}
