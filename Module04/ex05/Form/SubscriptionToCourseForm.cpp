#include "SubscriptionToCourseForm.hpp"

void SubscriptionToCourseForm::Execute()
{
	if (IsSigned() != true)
	{
		std::cout << "[SubscriptionToCourseForm]" << " Form is not signed !" << std::endl;
		return;
	}
	if (mCourse == nullptr || mStudent == nullptr)
	{
		std::cout << "[SubscriptionToCourseForm]" << " Course or Student is null !" << std::endl;
		return;
	}
	mCourse->Subscribe(mStudent);
    std::cout << "Executing Subscription To Course Form..." << std::endl;
}

void SubscriptionToCourseForm::Fill(Student *aStudent, Course *aCourse)
{
    mStudent = aStudent;
    mCourse = aCourse;
}
