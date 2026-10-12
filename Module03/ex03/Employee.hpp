#pragma once

class Employee
{
	protected :
		const int mHourlyValue;

	public :
		Employee(const int aHourlyValue) : mHourlyValue(aHourlyValue) {
		}
		virtual ~Employee() {
		}

		virtual int ExecuteWorkDay() = 0;
		virtual double GetSalary() const = 0;
};
