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
void Bank::SetLiquidity(int aLiquidity)
{
	this->mLiquidity = aLiquidity;
}
int Bank::GetLiquidity() const
{
	return this->mLiquidity;
}

int Bank::CreateAccount() const
{
	// Create account
	// Add account into std::map mClientAccounts
	// return id_account;
	return 0;
}
void Bank::DeleteAccount(int aId)
{
	(void)aId;
	// Delete account
	// Delete account in std::map mClientAccounts
}

void Bank::DepositMoney(int aId, int aMoney)
{
	mClientAccounts[aId]->mBalance += aMoney;
}
void Bank::WithdrawMoney(int aId, int aMoney)
{
	mClientAccounts[aId]->mBalance -= aMoney;
}
void Bank::GiveLoan(int aId, int aMoney)
{
	mClientAccounts[aId]->mLoan += aMoney;
}
void Bank::RetireLoan(int aId, int aMoney)
{
	mClientAccounts[aId]->mLoan -= aMoney;
}

const char *Bank::AccountIdNotExist::what() const throw()
{
	return ("\033[0;31mThis account id doesn't exist\033[0m");
}

// const Account &Bank::operator[](int aId)
// {
// 	std::map<int, Account *>::iterator	it;

// 	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
// 		throw Bank::AccountIdNotExist();
// 	return *(it->second);
// }

std::ostream &operator <<(std::ostream &aOut, const Bank &aBank)
{
	aOut << "Bank informations : " << std::endl;
	aOut << "Liquidity : " << aBank.GetLiquidity() << std::endl;
	for (std::map<int, Account *>::const_iterator it = aBank.mClientAccounts.begin(); it != aBank.mClientAccounts.end(); ++it)
		aOut << *(it->second) << std::endl;
	return (aOut);
}
