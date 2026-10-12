#pragma once

#include <iostream>

#include "Color.hpp"
#include "Employee.hpp"

class ContractEmployee : public Employee
{
	private :
		int mHoursWorked;
		int mAbsenceHours;

	public :
		ContractEmployee(const int aHourlyValue) : Employee(aHourlyValue), mHoursWorked(0), mAbsenceHours(0) {
		}
		~ContractEmployee() {
		}

		void AbsenceWork(int aHours) {
			mAbsenceHours += aHours;
		}
		int ExecuteWorkDay() {
			mHoursWorked += 7;
			std::cout << "[ContractEmployee]" << Blue << " execute workday : " << Yellow << 7 << " h" << Reset_Color << std::endl;
			return 7;
		}
		double GetSalary() const {
			int vEffectiveHours = mHoursWorked - mAbsenceHours;
			if (vEffectiveHours < 0)
				vEffectiveHours = 0;
			return vEffectiveHours * mHourlyValue;
		}
};
