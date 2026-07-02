#include "Bank.hpp"
#include "Account.hpp"

// My main
int main()
{
	// Account accountA = Account();
	// accountA.id = 0;
	// accountA.value = 100;

	// Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;

	// Bank bank = Bank();
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);

	// bank.liquidity -= 200;
	// accountA.value += 400;

	// std::cout << "Account : " << std::endl;
	// std::cout << accountA << std::endl;
	// std::cout << accountB << std::endl;

	// std::cout << " ----- " << std::endl;

	// std::cout << "Bank : " << std::endl;
	// std::cout << bank << std::endl;

	Bank vBank1 = Bank();
	vBank1.SetLiquidity(420);

	Bank vBank2 = Bank(1000);

	Bank vBank3 = Bank(vBank1);
	Bank vBank4 = vBank2;

	std::cout << "Bank1 liquidity : " << vBank1.GetLiquidity() << std::endl;
	std::cout << "Bank2 liquidity : " << vBank2.GetLiquidity() << std::endl;
	std::cout << "Bank1 copy construct liquidity : " << vBank3.GetLiquidity() << std::endl;
	std::cout << "Bank2 copy = liquidity : " << vBank4.GetLiquidity() << std::endl;

	return 0;
}

// // Exemple main
// int main(int argc, char **argv)
// {
// 	Account accountA = Account();
// 	accountA.id = 0;
// 	accountA.value = 100;

// 	Account accountB = Account();
// 	accountB.id = 1;
// 	accountB.value = 100;

// 	Bank bank = Bank();
// 	bank.liquidity = 999;
// 	bank.clientAccounts.push_back(&accountA);
// 	bank.clientAccounts.push_back(&accountB);

// 	bank.liquidity -= 200;
// 	accountA.value += 400;

// 	std::cout << "Account : " << std::endl;
// 	std::cout << accountA << std::endl;
// 	std::cout << accountB << std::endl;

// 	std::cout << " ----- " << std::endl;

// 	std::cout << "Bank : " << std::endl;
// 	std::cout << bank << std::endl;

// 	return 0;
// }
