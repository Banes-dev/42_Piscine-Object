#pragma once

#include "Room.hpp"

class Course;

class Classroom : public Room
{
	private :
		Course *mCurrentRoom;

	public :
		Classroom() : mCurrentRoom(nullptr) {
		}

		void AssignCourse(Course *aCourse);
};
