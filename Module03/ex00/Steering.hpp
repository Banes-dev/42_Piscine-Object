#pragma once

#include <iostream>

#include "Color.hpp"

class Steering
{
	public :
		Steering() {
		}
		~Steering() {
		}

		void turn_wheel(float aAngle, float &aCarAngle) {
			if (aAngle > 90.0f || aAngle < -90.0f)
				return;
			aCarAngle = aAngle;
			std::cout << "[Steering]" << Green << " turn wheel to " << aAngle << " degree" << Reset_Color << std::endl;
		}
		void straighten_wheels(float &aCarAngle) {
			aCarAngle = 0.0f;
			std::cout << "[Steering]" << Red << " straighten wheels" << Reset_Color << std::endl;
		}
};
