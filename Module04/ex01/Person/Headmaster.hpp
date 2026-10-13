#pragma once

#include <string>
#include <vector>

#include "Staff.hpp"

class Headmaster : public Staff
{
	private :
		std::vector<Form *> mFormToValidate;
		
	public :
		Headmaster(std::string aName) : Staff(aName) {
		}

		void receiveForm(Form *aForm);
};
