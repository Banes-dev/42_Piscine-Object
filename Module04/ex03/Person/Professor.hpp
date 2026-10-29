#pragma once

#include <string>
#include <memory>

#include "Staff.hpp"

class Course;
class Student;
class Headmaster;

class Professor : public Staff
{
	private :
		Course *mCurrentCourse;
		Headmaster *mHeadmaster;

	public :
		Professor(std::string aName) : Staff(aName), mCurrentCourse(nullptr), mHeadmaster(nullptr) {
		}
		~Professor() override = default;

		void AssignHeadmaster(Headmaster *aHeadmaster);

		void AssignCourse(Course *aCourse);
		void DoClass();
		void CloseCourse();

		void AskForNewCourse(std::string aCourseName);
		void AskForNewRoom();
		void ProposeGraduation(Student *aStudent);

		// Exceptions
		class HeadmasterNotAssignedException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mHeadmaster is not assigned to the professor\033[0m");}
		};
};
