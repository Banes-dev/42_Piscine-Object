#include "Bank.hpp"


unsigned int Bank::mNextId = 1;

// Constructor & Destructor
Bank::Bank() : mLiquidity(0)
{
}

Bank::Bank(double aLiquidity) : mLiquidity(aLiquidity)
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
		for (std::map<unsigned int, Account*>::const_iterator it = mClientAccounts.begin(); it != mClientAccounts.end(); ++it)
			delete it->second;
		this->mClientAccounts.clear();

		this->mLiquidity = copy.mLiquidity;
		for (std::map<unsigned int, Account*>::const_iterator it = copy.mClientAccounts.begin(); it != copy.mClientAccounts.end(); ++it)
			this->mClientAccounts.insert(std::pair<unsigned int, Account*>(it->first, new Account(*(it->second))));
	}
	return (*this);
}

Bank::~Bank()
{
	for (std::map<unsigned int, Account*>::const_iterator it = mClientAccounts.begin(); it != mClientAccounts.end(); ++it)
		delete it->second;
	this->mClientAccounts.clear();
}

// Others functions
void Bank::SetLiquidity(double aLiquidity)
{
	this->mLiquidity = aLiquidity;
}
double Bank::GetLiquidity() const
{
	return this->mLiquidity;
}

unsigned int Bank::CreateAccount(double aMoney)
{
	if (aMoney <= 0)
		throw Bank::NumberMustBePositive();
	// Create account
	// Account vAccount = new Account(mNextId, aMoney);
	// Add account into std::map mClientAccounts
	mClientAccounts.insert(std::pair<unsigned int, Account*>(mNextId, new Account(mNextId, aMoney)));
	return mNextId++;
}
void Bank::DeleteAccount(unsigned int aId)
{
	std::map<unsigned int, Account *>::iterator it;
	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	// Delete account
	delete it->second;
	mClientAccounts.erase(it);
}

void Bank::DepositMoney(unsigned int aId, double aMoney)
{
	if (aMoney <= 0)
		throw Bank::NumberMustBePositive();
	std::map<unsigned int, Account *>::iterator it;
	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	mLiquidity += aMoney * 0.05;
	mClientAccounts[aId]->mBalance += aMoney * 0.95;
}
void Bank::WithdrawMoney(unsigned int aId, double aMoney)
{
	if (aMoney <= 0)
		throw Bank::NumberMustBePositive();
	std::map<unsigned int, Account *>::iterator it;
	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	mClientAccounts[aId]->mBalance -= aMoney;
}
void Bank::GiveLoan(unsigned int aId, double aMoney)
{
	if (aMoney <= 0)
		throw Bank::NumberMustBePositive();
	std::map<unsigned int, Account *>::iterator it;
	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	mClientAccounts[aId]->mBalance += aMoney;
	mClientAccounts[aId]->mLoan += aMoney;
}
void Bank::RetireLoan(unsigned int aId, double aMoney)
{
	if (aMoney <= 0)
		throw Bank::NumberMustBePositive();
	std::map<unsigned int, Account *>::iterator it;
	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	mClientAccounts[aId]->mBalance -= aMoney;
	mClientAccounts[aId]->mLoan -= aMoney;
}

const char *Bank::AccountIdNotExist::what() const throw()
{
	return ("\033[0;31mThis account id doesn't exist\033[0m");
}
const char *Bank::NumberMustBePositive::what() const throw()
{
	return ("\033[0;31mNumber must be positive\033[0m");
}

const Account &Bank::operator[](unsigned int aId)
{
	std::map<unsigned int, Account *>::iterator	it;

	if ((it = mClientAccounts.find(aId)) == mClientAccounts.end())
		throw Bank::AccountIdNotExist();
	return *(it->second);
}

std::ostream &operator <<(std::ostream &aOut, const Bank &aBank)
{
	aOut << "Bank informations : " << std::endl;
	aOut << "Liquidity : " << aBank.GetLiquidity() << std::endl;
	for (std::map<unsigned int, Account *>::const_iterator it = aBank.mClientAccounts.begin(); it != aBank.mClientAccounts.end(); ++it)
		aOut << *(it->second) << std::endl;
	return (aOut);
}
