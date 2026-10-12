#include <iostream>

#include "Color.hpp"
#include "EmployeeManager.hpp"
#include "TempWorker.hpp"
#include "ContractEmployee.hpp"
#include "Apprentice.hpp"


int main()
{
	EmployeeManager manager;

	TempWorker temp(20);
	ContractEmployee contract(14);
	Apprentice apprentice(6);

	manager.AddEmployee(&temp);
	manager.AddEmployee(&contract);
	manager.AddEmployee(&apprentice);

	temp.MobilizeWork(10);
	contract.AbsenceWork(2);
	apprentice.RegisterSchool(9);

	std::cout << "--- Day 1 ---" << std::endl;
	manager.ExecuteWorkday();

	std::cout << "--- Day 2 ---" << std::endl;
	manager.ExecuteWorkday();

	std::cout << "--- End of Month ---" << std::endl;
	manager.CalculatePayroll();

	manager.RemoveEmployee(&temp);
	manager.RemoveEmployee(&contract);
	manager.RemoveEmployee(&apprentice);

    return 0;
}
