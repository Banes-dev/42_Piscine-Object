#include "Bank.hpp"


int Bank::mNextId = 0;

// Constructor & Destructor
Bank::Bank() : mLiquidity(0)
{
}

Bank::Bank(int aLiquidity) : mLiquidity(aLiquidity)
{
}

Bank::Bank(const Bank &copy)
{
	*this = copy;
}

Bank &Bank::operator=(const Bank &copy)
{
	if (this != &copy)
	{
		for (std::map<int, Account*>::const_iterator it = mClientAccounts.begin(); it != mClientAccounts.end(); ++it)
			delete it->second;
		this->mClientAccounts.clear();

		this->mLiquidity = copy.mLiquidity;
		for (std::map<int, Account*>::const_iterator it = copy.mClientAccounts.begin(); it != copy.mClientAccounts.end(); ++it)
			this->mClientAccounts.insert(std::pair<int, Account*>(it->first, new Account(*(it->second))));
	}
	return (*this);
}

Bank::~Bank()
{
	for (std::map<int, Account*>::const_iterator it = mClientAccounts.begin(); it != mClientAccounts.end(); ++it)
		delete it->second;
	this->mClientAccounts.clear();
}

// Others functions
void SetLiquidity(int aLiquidy)
{
	this->mLiquidity = aLiquidity;
}
int GetLiquidity() const
{
	return this->mLiquidity;
}

Account Bank::CreateAccount()
{
	// Create account
	// Add account into std::map mClientAccounts
	// return account;
}
void Bank::DeleteAccount(Account *aAccount)
{
	// Delete account
	// Delete account in std::map mClientAccounts
}

void Bank::DepositMoney(Account *aAccount, int aMoney)
{
	aAccount.mBalance += aMoney;
}
void Bank::WithdrawMoney(Account *aAccount, int aMoney)
{
	aAccount.mBalance -= aMoney;
}
void Bank::GiveLoan(Account *aAccount, int aMoney)
{
	aAccount.mLoan += aMoney;
}
void Bank::RetireLoan(Account *aAccount, int aMoney)
{
	aAccount.mLoan -= aMoney;
}

const char *Bank::AccountIdNotExist::what() const throw()
{
	return ("\033[0;31mThis account id doesn't exist\033[0m");
}

const Account &Bank::operator[](int aId)
{
	std::map<int, Account *>::iterator	it;

	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	return *(it->second);
}

std::ostream &operator <<(std::ostream &aOut, const Bank &aBank)
{
	aOut << "Bank informations : " << std::endl;
	aOut << "Liquidity : " << aBank.mLiquidity << std::endl;
	for (auto &clientAccount : aBank.mClientAccounts)
    aOut << *clientAccount << std::endl;
	return (aOut);
}
