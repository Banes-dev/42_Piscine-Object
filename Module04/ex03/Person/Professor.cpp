#include "Professor.hpp"
#include "Headmaster.hpp"
#include "../Course.hpp"

void Professor::AssignHeadmaster(std::shared_ptr<Headmaster> aHeadmaster)
{
    mCurrentHeadmaster = &aHeadmaster;
}

void Professor::AssignCourse(std::shared_ptr<Course> *aCourse)
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
    mHeadmaster->RequestCourseCreation(this, aCourseName);

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
