#pragma once

#include <string>
#include <vector>

#include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
	private :
		std::vector<Course *> mSubscribedCourse;

	public :
		Student(std::string A_Name) : Person(A_Name) {
		}
		~Student() override = default;

		void AttendClass(Classroom *aClassroom);
		void ExitClass();
		void Graduate(Course *aCourse);
};
