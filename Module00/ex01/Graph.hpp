#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <list>
#include "Vector2.hpp"
#include "LodePNG/lodepng.h"

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
		void CreateLine(float aX, float aY, float aX2, float aY2);
		void ReadPointsFromFile(std::string aFilename);
		void ResultAscii();
		void ResultPng(std::string aFilename, unsigned int aBackgroundColor[4], unsigned int aPointColor[4]);

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
		class CreatePngException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mError while creating png file\033[0m");}
		};
};
