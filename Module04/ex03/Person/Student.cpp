#include "Student.hpp"
#include "Headmaster.hpp"
#include "../Room/Classroom.hpp"
#include "../Course.hpp"


void Student::AssignHeadmaster(Headmaster *aHeadmaster)
{
    mHeadmaster = aHeadmaster;
}

void Student::AttendClass(Classroom *aClassroom)
{
    if (aClassroom)
        aClassroom->Enter(this);
}

void Student::ExitClass()
{
    if (mCurrentRoom)
        mCurrentRoom->Exit(this);
}

void Student::Graduate(Course *aCourse)
{
	std::cout << "[Student]" << " Graduated for the course " << aCourse->GetName() << std::endl;
}

void Student::AskToJoinCourse(Course *aCourse)
{
    if (mHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
    mHeadmaster->RequestCourseSubscription(this, aCourse);
}
