#pragma once

#include "Room.hpp"

class Course;

class Classroom : public Room
{
	private :
		Course *mCurrentCourse;

	public :
		Classroom() : mCurrentCourse(nullptr) {
		}

		void AssignCourse(Course *aCourse);
};
