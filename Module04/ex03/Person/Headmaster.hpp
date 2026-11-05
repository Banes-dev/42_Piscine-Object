#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Staff.hpp"

class Form;
class Secretary;
class Professor;
class Student;
class Course;

class Headmaster : public Staff
{
	private :
		std::vector<Form *> mFormToValidate;
		std::shared_ptr<Secretary> mSecretary;
		
	public :
		Headmaster(std::string aName) : Staff(aName), mSecretary(nullptr) {
		}
		~Headmaster() override = default;

		void ReceiveForm(Form *aForm);

		// Secretary
		void AssignSecretary(std::shared_ptr<Secretary> aSecretary);

		// Mediator
		void RequestGraduation(Student *aStudent, Course *aCourse);
		void RequestCourseCreation(std::string aCourseName);
		void RequestCourseSubscription(Student *aStudent, Course *aCourse);
		void RequestRoomCreation();

		// Exceptions
		class SecretaryNotAssignedException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mSecretary is not assigned to the headmaster\033[0m");}
		};
};
