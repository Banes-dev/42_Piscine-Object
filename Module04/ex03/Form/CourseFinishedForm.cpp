#include "CourseFinishedForm.hpp"

void CourseFinishedForm::Execute()
{
	if (IsSigned() != true)
	{
		std::cout << "[CourseFinishedForm]" << " Form is not signed !" << std::endl;
		return;
	}
	if (mCourse == nullptr || mStudent == nullptr)
	{
		std::cout << "[CourseFinishedForm]" << " Course or Student is null !" << std::endl;
		return;
	}
	mStudent->Graduate(mCourse);
    std::cout << "Executing Course Finished Form..." << std::endl;
}

void CourseFinishedForm::Fill(Student *aStudent, Course *aCourse)
{
    mStudent = aStudent;
    mCourse = aCourse;
}
