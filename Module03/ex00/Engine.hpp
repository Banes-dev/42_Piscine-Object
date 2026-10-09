#include <iostream>

#include "Color.hpp"

class Engine
{
	private :
		bool mIsStarted;

	public :
		Engine() {
		}
		~Engine() {
		}

		void start() {
			mIsStarted = true;
			std::cout << "[Engine]" << Green << " started" << Reset_Color << std::endl;
		}
		void stop() {
			mIsStarted = false;
			std::cout << "[Engine]" << Red << " stopped" << Reset_Color << std::endl;
		}
		void accelerate(float aSpeed, float &aCarSpeed) {
			if (!mIsStarted)
				return;
			if (aSpeed < 0.0f || aSpeed > 500.0f)
				return;
			aCarSpeed += aSpeed;
			std::cout << "[Engine]" << Blue << " accelerated, vehicle speed " << Yellow << aCarSpeed << " km/h" << Reset_Color << std::endl;
		}
};
