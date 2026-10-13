#pragma once

#include <iostream>

#include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
	public :
		NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {
		}
		~NeedMoreClassRoomForm() override = default;

		void Execute() override;
};
