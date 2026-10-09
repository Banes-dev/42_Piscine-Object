#pragma once

class Shape
{
	public :
		virtual ~Shape() {}

		virtual double GetArea() const = 0;
		virtual double GetPerimeter() const = 0;
};
