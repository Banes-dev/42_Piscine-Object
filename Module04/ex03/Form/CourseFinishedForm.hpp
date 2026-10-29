#pragma once

#include <iostream>
#include <memory>

#include "Form.hpp"
#include "../Course.hpp"
#include "../Person/Student.hpp"

class Course;
class Student;

class CourseFinishedForm : public Form
{
	private :
		Course *mCourse;
		Student *mStudent;

	public :
		CourseFinishedForm() : Form(FormType::CourseFinished), mCourse(nullptr), mStudent(nullptr) {
		}
		~CourseFinishedForm() override = default;

		void Execute() override;
		void Fill(Student *aStudent, Course *aCourse);
};
