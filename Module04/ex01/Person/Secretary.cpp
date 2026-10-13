#include "Secretary.hpp"
#include "../Form/CourseFinishedForm.hpp"
#include "../Form/NeedMoreClassRoomForm.hpp"
#include "../Form/NeedCourseCreationForm.hpp"
#include "../Form/SubscriptionToCourseForm.hpp"

Form *Secretary::CreateForm(FormType aFormType)
{
    switch (aFormType)
	{
        case FormType::CourseFinished: return new CourseFinishedForm();
        case FormType::NeedMoreClassRoom: return new NeedMoreClassRoomForm();
        case FormType::NeedCourseCreation: return new NeedCourseCreationForm();
        case FormType::SubscriptionToCourse: return new SubscriptionToCourseForm();
        default: return nullptr;
    }
}

void Secretary::ArchiveForm()
{
}