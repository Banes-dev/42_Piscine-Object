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
		std::shared_ptr<Course> mCourse;
		std::shared_ptr<Student> mStudent;

	public :
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse), mCourse(nullptr), mStudent(nullptr) {
		}
		~SubscriptionToCourseForm() override = default;

		void Execute() override;
		void Fill(std::shared_ptr<Student> aStudent, std::shared_ptr<Course> aCourse);
};
