#pragma once

#include <string>
#include <memory>

#include "Staff.hpp"
#include "../Form/Form.hpp"

class Form;
enum class FormType;

class Secretary : public Staff
{
	private :

	public :
		Secretary(std::string aName) : Staff(aName) {
		}

		std::shared_ptr<Form> CreateForm(FormType aFormType);
		void ArchiveForm();
};
