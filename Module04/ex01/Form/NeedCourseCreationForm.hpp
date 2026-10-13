#pragma once

#include <iostream>

#include "Form.hpp"

class NeedCourseCreationForm : public Form
{
	public :
		NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {
		}
		~NeedCourseCreationForm() override = default;

		void Execute() override;
};
