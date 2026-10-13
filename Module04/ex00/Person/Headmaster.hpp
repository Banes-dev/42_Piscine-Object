#pragma once

#include <vector>

#include "Staff.hpp"

class Headmaster : public Staff
{
	private :
		std::vector<Form *> mFormToValidate;
		
	public :
		void receiveForm(Form *aForm);
};
