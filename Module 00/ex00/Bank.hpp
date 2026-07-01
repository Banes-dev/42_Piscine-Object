#pragma once

#include <iostream>
#include <map>

#include "Account.hpp"

class Bank
{
	private :
		double mLiquidity;
		std::map<int, Account *> mClientAccounts;
		static int mNextId;

	public :
		// Constructor & Destructor
		Bank();
		Bank(int aLiquidity);
		Bank(const Bank &copy);
		Bank &operator=(const Bank &copy);
		~Bank();

		// Others functions
		void SetLiquidity(int aLiquidy);
		int GetLiquidity();

		Account CreateAccount();
		void DeleteAccount(Account *aAccount);

		void DepositMoney(Account *aAccount, int aMoney);
		void WithdrawMoney(Account *aAccount, int aMoney);
		void GiveLoan(Account *aAccount, int aMoney);
		void RetireLoan(Account *aAccount, int aMoney);

		class AccountIdNotExist : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		const Account &operator[](int);
}

std::ostream &operator <<(std::ostream &aOut, const Bank &aBank)
