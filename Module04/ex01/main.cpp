#include <iostream>
#include <memory>

#include "Color.hpp"
#include "Singletons.hpp"
#include "Person/Student.hpp"
#include "Person/Headmaster.hpp"
#include "Course.hpp"
#include "Room/Classroom.hpp"

int main()
{
    std::cout << Cyan << "--- Singletons Init ---" << Reset_Color << std::endl;

    StudentList &students = StudentList::GetInstance();
    StaffList &staff = StaffList::GetInstance();
    CourseList &courses = CourseList::GetInstance();
    RoomList &rooms = RoomList::GetInstance();

    std::shared_ptr<Student> s1 = std::make_shared<Student>("Alice");
    std::shared_ptr<Student> s2 = std::make_shared<Student>("Bob");
    std::shared_ptr<Headmaster> hm = std::make_shared<Headmaster>("Mr. Principal");
    std::shared_ptr<Course> math = std::make_shared<Course>("Math 101");
    std::shared_ptr<Classroom> roomA = std::make_shared<Classroom>();

    std::cout << Yellow << Arrow_right << " Populating the lists..." << Reset_Color << std::endl;
    
    students.Add(s1);
    students.Add(s2);
    staff.Add(hm);
    courses.Add(math);
    rooms.Add(roomA);

    std::cout << Blue << "Number of students : " << White << StudentList::GetInstance().Get().size() << Reset_Color << std::endl;
    std::cout << Blue << "Number of staff    : " << White << StaffList::GetInstance().Get().size() << Reset_Color << std::endl;
    std::cout << Blue << "Number of courses  : " << White << CourseList::GetInstance().Get().size() << Reset_Color << std::endl;
    std::cout << Blue << "Number of rooms    : " << White << RoomList::GetInstance().Get().size() << Reset_Color << std::endl;

    return 0;
}
