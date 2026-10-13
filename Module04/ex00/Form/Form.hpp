#pragma once

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
	private :
		FormType mFormType;

	public :
		Form(FormType aFormType) : mFormType(aFormType) {
			(void)mFormType;
		}
		virtual ~Form() = default;

		virtual void Execute() = 0;
};
