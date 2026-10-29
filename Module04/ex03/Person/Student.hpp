#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Person.hpp"

class Course;
class Classroom;
class Headmaster;

class Student : public Person
{
	private :
		std::vector<Course *> mSubscribedCourse;
		Headmaster *mHeadmaster;

	public :
		Student(std::string aName) : Person(aName), mHeadmaster(nullptr) {
		}
		~Student() override = default;

		void AssignHeadmaster(Headmaster *aHeadmaster);

		void AttendClass(Classroom *aClassroom);
		void ExitClass();
		void Graduate(Course *aCourse);

		void AskToJoinCourse(Course *aCourse);

		// Exceptions
		class HeadmasterNotAssignedException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mHeadmaster is not assigned to the student\033[0m");}
		};
};
