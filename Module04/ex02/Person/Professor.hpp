#pragma once

#include <string>

#include "Staff.hpp"

class Course;

class Professor : public Staff
{
	private :
		Course *mCurrentCourse;

	public :
		Professor(std::string aName) : Staff(aName) {
		}

		void AssignCourse(Course *aCourse);
		void DoClass();
		void CloseCourse();
};
