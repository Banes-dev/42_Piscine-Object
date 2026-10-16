#pragma once

#include <string>

class Room;

class Person
{
	protected :
		const std::string mName;
		Room *mCurrentRoom;

	public :
		Person(std::string aName) : mName(aName), mCurrentRoom(nullptr) {
		}
		virtual ~Person() = default;

		std::string GetName() const {
			return (mName);
		}
		Room *GetRoom() const {
			return (mCurrentRoom);
		}
		void SetRoom(Room *aRoom) {
			mCurrentRoom = aRoom;
		}
};
