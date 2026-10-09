#include <iostream>

#include "Color.hpp"

class Gearbox
{
	private :
		int mGear;

	public :
		Gearbox() : mGear(0) {
		}
		~Gearbox() {
		}

		void shift_up() {
			if (mGear >= 6)
				return;
			mGear++;
			std::cout << "[Gearbox]" << Green << " shift up to " << mGear << Reset_Color << std::endl;
		}
		void shift_down() {
			if (mGear <= 0)
				return;
			mGear--;
			std::cout << "[Gearbox]" << Red << " shift down to " << mGear << Reset_Color << std::endl;
		}
		void reverse() {
			mGear = -1;
			std::cout << "[Gearbox]" << Purple << " reverse to " << mGear << Reset_Color << std::endl;
		}
};
