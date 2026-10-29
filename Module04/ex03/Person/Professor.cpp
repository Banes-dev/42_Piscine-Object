#include "Professor.hpp"
#include "Headmaster.hpp"
#include "../Course.hpp"

void Professor::AssignHeadmaster(Headmaster *aHeadmaster)
{
    mHeadmaster = aHeadmaster;
}

void Professor::AssignCourse(Course *aCourse)
{
    mCurrentCourse = aCourse;
}

void Professor::DoClass()
{
}

void Professor::CloseCourse()
{
    mCurrentCourse = nullptr;
}

void Professor::AskForNewCourse(std::string aCourseName)
{
    if (mHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
    mHeadmaster->RequestCourseCreation(aCourseName);

}

void Professor::AskForNewRoom()
{
    if (mHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
	mHeadmaster->RequestRoomCreation();
}

void Professor::ProposeGraduation(Student *aStudent)
{
    if (mHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
	Course *vCourse = mCurrentCourse;
	if (vCourse)
		mHeadmaster->RequestGraduation(aStudent, vCourse);
}
