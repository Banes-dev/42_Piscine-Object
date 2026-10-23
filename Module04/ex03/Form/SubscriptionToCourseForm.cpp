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
	mCourse->Subscribe(mStudent.get());
    std::cout << "Executing Subscription To Course Form..." << std::endl;
}

void SubscriptionToCourseForm::Fill(std::shared_ptr<Student> aStudent, std::shared_ptr<Course> aCourse)
{
    mStudent = aStudent;
    mCourse = aCourse;
}
