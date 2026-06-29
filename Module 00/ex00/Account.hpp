#pragma once

#include <iostream>
#include "Bank.hpp"

class Account
{
	private :
		int mId;
		int mMoney;
		
		// Constructor & Destructor
		Account();
		~Account();

		friend class Bank;

	public :
		// Others functions
		int GetId();
		int GetMoney();
}
