#pragma once

#include <iostream>

#include "Color.hpp"
#include "Employee.hpp"

class TempWorker : public Employee
{
	private :
		int mHoursToWork;
		int mHoursWorked;

	public :
		TempWorker(const int aHourlyValue) : Employee(aHourlyValue), mHoursToWork(0), mHoursWorked(0) {
		}
		~TempWorker() {
		}

		void MobilizeWork(int aHours) {
			mHoursToWork += aHours;
		}
		int ExecuteWorkDay() {
			int workToday = 0;
			if (mHoursToWork >= 7)
				workToday = 7;
			else
				workToday = mHoursToWork;
			mHoursToWork -= workToday;
			mHoursWorked += workToday;
			
			std::cout << "[TempWorker]" << Blue << " execute workday : " << Yellow << workToday << " h" << Reset_Color << std::endl;
			return workToday;
		}
		double GetSalary() const {
			double vSalary = mHourlyValue * mHoursWorked;
			return vSalary;
		}
};
