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
    if (mCurrentHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
    mCurrentHeadmaster->RequestCourseCreation(aCourseName);

}

void Professor::AskForNewRoom()
{
    if (mCurrentHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
	// todo
}

void Professor::ProposeGraduation(Student *aStudent)
{
    if (mCurrentHeadmaster == nullptr)
	{
		throw HeadmasterNotAssignedException();
		return;
	}
	Course *vCourse = mCurrentCourse;
	if (vCourse)
		mCurrentHeadmaster->RequestGraduation(aStudent, vCourse);
}
