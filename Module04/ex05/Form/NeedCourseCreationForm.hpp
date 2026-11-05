#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"
#include "../Course.hpp"
#include "../Singletons.hpp"

class NeedCourseCreationForm : public Form
{
	private :
		std::string mCourseName;

	public :
		NeedCourseCreationForm() : Form(FormType::NeedCourseCreation), mCourseName("") {
		}
		~NeedCourseCreationForm() override = default;

		void Execute() override;
		void Fill(std::string aCourseName);
};
