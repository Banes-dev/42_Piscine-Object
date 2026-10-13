#pragma once

#include "Person.hpp"

class Form;

class Staff : public Person
{
	private :

	public :
		void Sign(Form *aForm);
};
