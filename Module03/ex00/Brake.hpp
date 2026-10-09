#include <iostream>

#include "Color.hpp"

class Brake
{
	public :
		Brake() {
		}
		~Brake() {
		}

		void apply_force(float aForce, float &aCarSpeed) {
			if (aForce < 0.0f || aForce > 100.0f)
				return;
			aCarSpeed -= aForce;
			if (aCarSpeed < 0.0f)
				aCarSpeed = 0.0f;
			std::cout << "[Brake]" << Green << " apply force " << aForce << " N, vehicle speed " << Yellow << aCarSpeed << " km/h" << Reset_Color << std::endl;
		}
		void apply_emergency_brakes(float &aCarSpeed) {
			aCarSpeed -= 100.0f;
			if (aCarSpeed < 0.0f)
				aCarSpeed = 0.0f;
			std::cout << "[Brake]" << Red << " apply emergency brakes, vehicle speed " << Yellow << aCarSpeed << " km/h" << Reset_Color << std::endl;
		}
};
