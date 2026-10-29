#pragma once

#include <string>

#include "Person.hpp"

class Form;

class Staff : public Person
{
	private :

	public :
		Staff(std::string aName) : Person(aName) {
		}
		~Staff() override = default;

		void Sign(Form *aForm);
};
