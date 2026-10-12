#pragma once

#include <iostream>

#include "Color.hpp"
#include "Employee.hpp"

class Apprentice : public Employee
{
private :
		int mHoursWorked;
		int mAbsenceHours;
		int mSchoolHoursToAttend;
		int mSchoolHoursAttended;

	public :
		Apprentice(const int aHourlyValue) : Employee(aHourlyValue), mHoursWorked(0), mAbsenceHours(0), mSchoolHoursToAttend(0), mSchoolHoursAttended(0) {
		}
		~Apprentice() {
		}

		void RegisterAbsence(int aHours) {
			mAbsenceHours += aHours;
		}
		void RegisterSchool(int aHours) {
			mSchoolHoursToAttend += aHours;
		}
		int ExecuteWorkDay() {
			int hoursAtSchool = 0;
			int hoursAtWork = 0;

			if (mSchoolHoursToAttend >= 7)
				hoursAtSchool = 7;
			else {
				hoursAtSchool = mSchoolHoursToAttend;
				hoursAtWork = 7 - mSchoolHoursToAttend;
			}

			mSchoolHoursToAttend -= hoursAtSchool;
			mSchoolHoursAttended += hoursAtSchool;
			mHoursWorked += hoursAtWork;

			std::cout << "[Apprentice]" << Blue << " work : " << Yellow << hoursAtWork << " h" << Blue << ", school : " << Yellow << hoursAtSchool << " h" << Reset_Color << std::endl;
			return 7;
		}

		double GetSalary() const {
			int vEffectiveWorkHours = mHoursWorked - mAbsenceHours;
			if (vEffectiveWorkHours < 0)
				vEffectiveWorkHours = 0;
			return (vEffectiveWorkHours * mHourlyValue) + (mSchoolHoursAttended * (mHourlyValue / 2.0));
		}
};
