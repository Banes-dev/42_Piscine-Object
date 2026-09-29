#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <list>
#include "Vector2.hpp"

class Vector2;

class Graph
{
	private :
		Vector2 mSize;
		std::list<Vector2 *> mPoints;

	public :
		// Constructor & Destructor
		Graph(Vector2 aSize); 
		~Graph();

		// Others functions
		void CreatePoint(float aX, float aY);
		void ReadPointsFromFile(std::string aFilename);
		void ResultAscii();
		void ResultPng(std::string aFilename);

		// Exceptions
		class NumberMustBePositive : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mNumber must be positive\033[0m");}
		};
		class PositionPointMustBeValid : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mThe position of a point must be in the graph\033[0m");}
		};
		class BadParsingException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mPoints list parsing error\033[0m");}
		};
		class PngFileMustBeValid : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mThe filename must be a png file\033[0m");}
		};
};
