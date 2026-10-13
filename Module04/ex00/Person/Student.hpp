#pragma once

#include <vector>

#include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
	private :
		std::vector<Course *> mSubscribedCourse;

	public :
		void AttendClass(Classroom *aClassroom);
		void ExitClass();
		void Graduate(Course *aCourse);
};
