#pragma once

#include <string>

#include "Staff.hpp"
#include "../Form/Form.hpp"

class Secretary : public Staff
{
	private :

	public :
		Secretary(std::string aName) : Staff(aName) {
		}

		Form *CreateForm(FormType aFormType);
		void ArchiveForm();
};
