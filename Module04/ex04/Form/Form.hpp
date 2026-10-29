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
		bool mSigned;

	public :
		Form(FormType aFormType) : mFormType(aFormType), mSigned(false) {
			(void)mFormType;
		}
		virtual ~Form() = default;

		virtual void Execute() = 0;

		void Sign() {
			mSigned = true;
		}
		bool IsSigned() const {
			return mSigned;
		}
};
