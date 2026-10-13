#pragma once

#include <vector>
#include <memory>

class Student;
class Staff;
class Course;
class Room;

template <typename T>
class SingletonList
{
	private :
		std::vector<std::shared_ptr<T>> mList;

		SingletonList() = default;
		~SingletonList() = default;

		SingletonList(const SingletonList &) = delete;
		SingletonList &operator=(const SingletonList &) = delete;

	public :
		static SingletonList &GetInstance() {
			static SingletonList instance;
			return instance;
		}

		void Add(std::shared_ptr<T> item) {
			if (item)
				mList.push_back(item);
		}
		
		const std::vector<std::shared_ptr<T>> &Get() const {
			return mList;
		}
};

using StudentList = SingletonList<Student>;
using StaffList   = SingletonList<Staff>;
using CourseList  = SingletonList<Course>;
using RoomList    = SingletonList<Room>;