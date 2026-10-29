#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "Staff.hpp"
#include "../Observer.hpp"

class Course;
class Student;
class Headmaster;

class Professor : public Staff, public IObserver
{
	private :
		Course *mCurrentCourse;
		Headmaster *mHeadmaster;
		bool mIsOnBreak;

	public :
		Professor(std::string aName) : Staff(aName), mCurrentCourse(nullptr), mHeadmaster(nullptr), mIsOnBreak(false) {
		}
		~Professor() override = default;

		void AssignHeadmaster(Headmaster *aHeadmaster);

		void AssignCourse(Course *aCourse);
		void DoClass();
		void CloseCourse();

		void AskForNewCourse(std::string aCourseName);
		void AskForNewRoom();
		void ProposeGraduation(Student *aStudent);

		void Notify(Event aEvent) override;

		// Exceptions
		class HeadmasterNotAssignedException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mHeadmaster is not assigned to the professor\033[0m");}
		};
};
