#include "Vector2.hpp"


// Constructor & Destructor
Vector2::Vector2(float aX, float aY) : mX(aX), mY(aY)
{
}

Vector2::~Vector2()
{
}

// Others functions
float Vector2::GetX() const
{
	return this->mX;
}

float Vector2::GetY() const
{
	return this->mY;
}

void Vector2::SetX(float aX)
{
	if (std::isnan(aX) || aX < 0)
		throw NumberMustBePositive();
	this->mX = aX;
}

void Vector2::SetY(float aY)
{
	if (std::isnan(aY) || aY < 0)
		throw NumberMustBePositive();
	this->mY = aY;
}
