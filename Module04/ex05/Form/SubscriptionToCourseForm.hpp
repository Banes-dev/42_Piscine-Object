#pragma once

#include <iostream>
#include <memory>

#include "Form.hpp"
#include "../Course.hpp"
#include "../Person/Student.hpp"

class Course;
class Student;

class SubscriptionToCourseForm : public Form
{
	private :
		Course *mCourse;
		Student *mStudent;

	public :
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse), mCourse(nullptr), mStudent(nullptr) {
		}
		~SubscriptionToCourseForm() override = default;

		void Execute() override;
		void Fill(Student *aStudent, Course *aCourse);
};
