#pragma once

#include <iostream>

#include "Form.hpp"

class SubscriptionToCourseForm : public Form
{
	public :
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {
		}
		~SubscriptionToCourseForm() override = default;

		void Execute() override;
};
