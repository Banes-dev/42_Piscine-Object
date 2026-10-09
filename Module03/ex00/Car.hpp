#pragma once

#include "Engine.hpp"
#include "Gearbox.hpp"
#include "Steering.hpp"
#include "Brake.hpp"

class Car
{
	private :
		float mSpeed;
		float mAngle;
		Engine mEngine;
		Gearbox mGearbox;
		Steering mSteering;
		Brake mBrake;

	public :
		Car() : mSpeed(0.0f), mAngle(0.0f) {
		}
		~Car() {
		}

		void start() {
			mEngine.start();
		}
		void stop() {
			mBrake.apply_emergency_brakes(mSpeed);
			mEngine.stop();
		}
		void accelerate(float aSpeed) {
			mEngine.accelerate(aSpeed, mSpeed);
		}
		void shift_gears_up() {
			mGearbox.shift_up();
		}
		void shift_gears_down() {
			mGearbox.shift_down();
		}
		void reverse() {
			mGearbox.reverse();
		}
		void turn_wheel(float aAngle) {
			mSteering.turn_wheel(aAngle, mAngle);
		}
		void straighten_wheels() {
			mSteering.straighten_wheels(mAngle);
		}
		void apply_force_on_brakes(float aForce) {
			mBrake.apply_force(aForce, mSpeed);
		}
		void apply_emergency_brakes() {
			mBrake.apply_emergency_brakes(mSpeed);
		}
};
