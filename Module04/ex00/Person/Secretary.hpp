#pragma once

#include "Staff.hpp"
#include "../Form/Form.hpp"

class Secretary : public Staff
{
	private :

	public :
		Form *CreateForm(FormType aFormType);
		void ArchiveForm();
};
