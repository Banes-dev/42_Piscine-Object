#pragma once

#include <cmath> // std::sqrt

#include "Shape.hpp"

class Triangle : public Shape
{
	private :
		double mSideA;
		double mSideB;
		double mSideC;

	public :
		Triangle(double aSideA, double aSideB, double aSideC) 
            : mSideA(aSideA), mSideB(aSideB), mSideC(aSideC) {
		}
		~Triangle() {
		}

		double GetArea() const {
			double vPerpendicularSide = (mSideA + mSideB + mSideC) / 2.0;
			return std::sqrt(vPerpendicularSide * (vPerpendicularSide - mSideA) * (vPerpendicularSide - mSideB) * (vPerpendicularSide - mSideC));
		}
		double GetPerimeter() const {
			return mSideA + mSideB + mSideC;
		}
};
