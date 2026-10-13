#pragma once

#include "Staff.hpp"

class Course;

class Professor : public Staff
{
	private :
		Course *mCurrentCourse;

	public :
		void AssignCourse(Course *aCourse);
		void DoClass();
		void CloseCourse();
};
