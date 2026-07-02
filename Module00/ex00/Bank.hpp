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
		void SetLiquidity(int aLiquidity);
		int GetLiquidity() const;

		int CreateAccount() const;
		void DeleteAccount(int aId);

		void DepositMoney(int aId, int aMoney);
		void WithdrawMoney(int aId, int aMoney);
		void GiveLoan(int aId, int aMoney);
		void RetireLoan(int aId, int aMoney);

		class AccountIdNotExist : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		// const Account &operator[](int);

		friend std::ostream &operator <<(std::ostream &aOut, const Bank &aBank);
};
