#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
	private :
		double mWidth;
		double mHeight;

	public :
		Rectangle(double aWidth, double aHeight) : mWidth(aWidth), mHeight(aHeight) {
		}
		~Rectangle() {
		}

		double GetArea() const {
			return mWidth * mHeight;
		}
		double GetPerimeter() const {
			return 2.0f * (mWidth + mHeight);
		}
};
