#pragma once

#include <iostream>
#include <vector>

class Person;

class Room
{
	private :
		long long mId;
		std::vector<Person *> mOccupants;

	public :
		Room() : mId(0) {
		}
		virtual ~Room() = default;

		bool CanEnter(Person *);
		void Enter(Person *);
		void Exit(Person *);
		void PrintOccupant();
		long long GetId() const {
			return mId;
		}
};
