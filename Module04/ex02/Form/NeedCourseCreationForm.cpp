#include "NeedCourseCreationForm.hpp"

void NeedCourseCreationForm::Execute()
{
	if (IsSigned() != true)
	{
		std::cout << "[NeedCourseCreationForm]" << " Form is not signed !" << std::endl;
		return;
	}
	if (mCourseName.empty())
	{
		std::cout << "[NeedCourseCreationForm]" << " Course name is empty !" << std::endl;
		return;
	}
	auto newCourse = std::make_shared<Course>(mCourseName);
    CourseList::GetInstance().Add(newCourse);
	std::cout << "[NeedCourseCreationForm]" << " Course " << mCourseName << " created !" << std::endl;
}

void NeedCourseCreationForm::Fill(std::string aCourseName)
{
    mCourseName = aCourseName;
}
