#pragma once

#include <string>
#include <vector>

class Student;
class Professor;

class Course
{
	private :
		std::string mName;
		Professor *mResponsable;
		std::vector<Student *> mStudents;
		int mNumberOfClassToGraduate;
		int mMaximumNumberOfStudent;

	public :
		Course(std::string aName) : mName(aName), mResponsable(nullptr), mNumberOfClassToGraduate(0), mMaximumNumberOfStudent(30) {
		}

		void Assign(Professor *aProfessor);
		void Subscribe(Student *aStudent);
};
