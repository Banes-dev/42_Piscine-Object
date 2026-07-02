#include "Bank.hpp"
#include "Account.hpp"

// My main
int main()
{
	try
	{
		Bank vBank1 = Bank();
		vBank1.SetLiquidity(420);

		Bank vBank2 = Bank(1000);

		Bank vBank3 = Bank(vBank1);
		Bank vBank4 = vBank2;

		std::cout << "Bank1 liquidity : " << vBank1.GetLiquidity() << std::endl;
		std::cout << "Bank2 liquidity : " << vBank2.GetLiquidity() << std::endl;
		std::cout << "Bank1 copy construct liquidity : " << vBank3.GetLiquidity() << std::endl;
		std::cout << "Bank2 copy = liquidity : " << vBank4.GetLiquidity() << std::endl << std::endl;

		try
		{
			unsigned int vTestAccount = vBank1.CreateAccount(42);
			std::cout << "vTestAccount : " << vBank1[vTestAccount] << std::endl;
			vBank1.DeleteAccount(vTestAccount);
			std::cout << "vTestAccount : " << vBank1[vTestAccount] << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		unsigned int vAccount1 = vBank1.CreateAccount(42);
		std::cout << std::endl << "vAccount1 : " << vBank1[vAccount1] << std::endl;
		vBank1.DepositMoney(vAccount1, 100);
		std::cout << "vAccount1 : " << vBank1[vAccount1] << std::endl;
		vBank1.WithdrawMoney(vAccount1, 40);
		std::cout << "vAccount1 : " << vBank1[vAccount1] << std::endl;
		vBank1.GiveLoan(vAccount1, 86);
		std::cout << "vAccount1 : " << vBank1[vAccount1] << std::endl;
		vBank1.RetireLoan(vAccount1, 44);
		std::cout << "vAccount1 : " << vBank1[vAccount1] << std::endl << std::endl;

		unsigned int vAccount2 = vBank1.CreateAccount(666);
		std::cout << vBank1 << std::endl << std::endl;

		try {
			std::cout << "Error not good id : " << vBank1[42] << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			vBank1.DepositMoney(vAccount2, 0);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
