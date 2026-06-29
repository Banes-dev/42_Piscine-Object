#pragma once

#include <iostream>
#include <vector>

class Bank
{
	private :
		int mLiquidity;
		std::vector<Account *> clientAccounts;

	public :
		// Constructor & Destructor
		Bank();
		Bank(int aLiquidity);
		~Bank();

		// Others functions
		void SetLiquidity(int aLiquidy);
		int GetLiquidity();

		Account CreateAccount();
		void DeleteAccount(Account *aAccount);

		void DepositMoney(Account *aAccount, int aMoney);
		void WithdrawMoney(Account *aAccount, int aMoney);
		void GiveLoan(Account *aAccount, int aMoney);

		std::ostream &operator <<(std::ostream &aOutput, const Bank &aBank)
}
