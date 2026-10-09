
#include <iostream>
#include "Car.hpp"

int main()
{
	Car car;

	// Engine
	car.start();
	car.accelerate(42.42f);
	car.stop();
	car.accelerate(100.00f);
	car.start();
	std::cout << std::endl;

	// Gearbox
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up(); // 7 gears not set
	car.shift_gears_down();
	car.reverse();
	std::cout << std::endl;

	// Steering
	car.turn_wheel(90.0f);
	car.turn_wheel(42.42f);
	car.turn_wheel(-90.0f);
	car.turn_wheel(91.0f);
	car.turn_wheel(-91.0f);
	std::cout << std::endl;

	// Brake
	car.apply_force_on_brakes(42.42f);
	car.accelerate(142.00f);
	car.apply_force_on_brakes(80.0f);
	car.accelerate(142.00f);
	car.apply_emergency_brakes();

    return 0;
}
