#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
	private :
		double mRadius;

	public :
		Circle(double aRadius) : mRadius(aRadius) {
		}
		~Circle() {
		}

		double GetArea() const {
			return 3.1415926535 * mRadius * mRadius; 	// area = pi * r * r
		}
		double GetPerimeter() const {
			return 2.0 * 3.1415926535 * mRadius;		// perimeter = 2 * pi * r
		}
};
