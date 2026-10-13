#pragma once

#include <iostream>

#include "Form.hpp"

class CourseFinishedForm : public Form
{
	public :
		CourseFinishedForm() : Form(FormType::CourseFinished) {
		}
		~CourseFinishedForm() override = default;

		void Execute() override;
};
