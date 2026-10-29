#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Person.hpp"
#include "../Observer.hpp"

class Course;
class Classroom;
class Headmaster;

class Student : public Person, public IObserver
{
	private :
		std::vector<Course *> mSubscribedCourse;
		Headmaster *mHeadmaster;
		bool mIsOnBreak;

	public :
		Student(std::string aName) : Person(aName), mHeadmaster(nullptr), mIsOnBreak(false) {
		}
		~Student() override = default;

		void AssignHeadmaster(Headmaster *aHeadmaster);

		void AttendClass(Classroom *aClassroom);
		void ExitClass();
		void Graduate(Course *aCourse);

		void AskToJoinCourse(Course *aCourse);

		void Notify(Event aEvent) override;

		// Exceptions
		class HeadmasterNotAssignedException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mHeadmaster is not assigned to the student\033[0m");}
		};
};
