#pragma once

#include <iostream>
#include <map>

#include "Account.hpp"

class Bank
{
	private :
		double mLiquidity;
		std::map<unsigned int, Account *> mClientAccounts;
		static unsigned int mNextId;

	public :
		// Constructor & Destructor
		Bank();
		Bank(double aLiquidity);
		Bank(const Bank &copy);
		Bank &operator=(const Bank &copy);
		~Bank();

		// Others functions
		void SetLiquidity(double aLiquidity);
		double GetLiquidity() const;

		unsigned int CreateAccount(double aMoney);
		void DeleteAccount(unsigned int aId);

		void DepositMoney(unsigned int aId, double aMoney);
		void WithdrawMoney(unsigned int aId, double aMoney);
		void GiveLoan(unsigned int aId, double aMoney);
		void RetireLoan(unsigned int aId, double aMoney);

		class AccountIdNotExist : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class NumberMustBePositive : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		const Account &operator[](unsigned int);

		friend std::ostream &operator <<(std::ostream &aOut, const Bank &aBank);
};
