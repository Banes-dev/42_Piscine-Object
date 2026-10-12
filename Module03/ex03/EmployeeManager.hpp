#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

#include "Color.hpp"
#include "Employee.hpp"

class EmployeeManager
{
	private :
		std::vector<Employee *> mEmployees;

	public :
		EmployeeManager() {
		}
		~EmployeeManager() {
		}

		void AddEmployee(Employee *aEmployee) {
			mEmployees.push_back(aEmployee);
		}
		void RemoveEmployee(Employee *aEmployee) {
			mEmployees.erase(std::remove(mEmployees.begin(), mEmployees.end(), aEmployee), mEmployees.end());
		}
		void ExecuteWorkday() {
			for (std::vector<Employee *>::iterator it = mEmployees.begin(); it != mEmployees.end(); ++it) {
				(*it)->ExecuteWorkDay();
			}
		}
		void CalculatePayroll() {
			for (std::vector<Employee *>::iterator it = mEmployees.begin(); it != mEmployees.end(); ++it)
				std::cout << "[EmployeeManager]" << Purple << " payroll of " << Yellow << (*it)->GetSalary() << " $" << Reset_Color << std::endl;
		}
};
