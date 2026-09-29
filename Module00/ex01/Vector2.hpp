#pragma once

#include <iostream>
#include <cmath>

class Vector2
{
	private :
		float mX;
		float mY;

	public :
		// Constructor & Destructor
		Vector2(float aX, float aY);
		~Vector2();

		// Others functions
		float GetX() const;
		float GetY() const;

		void SetX(float aX);
		void SetY(float aY);

		class NumberMustBePositive : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
