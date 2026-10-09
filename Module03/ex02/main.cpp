#include <iostream>

#include "Color.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

double CalculateArea(Shape *aShape)
{
	return aShape->GetArea();
}

double CalculatePerimeter(Shape *aShape)
{
	return aShape->GetPerimeter();
}

int main()
{
	Circle circle(4.2);
	Rectangle rectangle(2.0, 4.0);
	Triangle triangle(3.0, 4.0, 5.0);

	std::cout << "[CalculateArea]" << Green << " calculate area of circle " << Yellow << CalculateArea(&circle) << " m²" << Reset_Color << std::endl;
	std::cout << "[CalculateArea]" << Green << " calculate area of rectangle " << Yellow << CalculateArea(&rectangle) << " m²" << Reset_Color << std::endl;
	std::cout << "[CalculateArea]" << Green << " calculate area of triangle " << Yellow << CalculateArea(&triangle) << " m²" << Reset_Color << std::endl;

	std::cout << "[CalculatePerimeter]" << Green << " calculate perimeter of circle " << Yellow << CalculatePerimeter(&circle) << " m" << Reset_Color << std::endl;
	std::cout << "[CalculatePerimeter]" << Green << " calculate perimeter of rectangle " << Yellow << CalculatePerimeter(&rectangle) << " m" << Reset_Color << std::endl;
	std::cout << "[CalculatePerimeter]" << Green << " calculate perimeter of triangle " << Yellow << CalculatePerimeter(&triangle) << " m" << Reset_Color << std::endl;

    return 0;
}
