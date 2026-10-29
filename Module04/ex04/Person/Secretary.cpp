#include "Secretary.hpp"
#include "../Form/CourseFinishedForm.hpp"
#include "../Form/NeedMoreClassRoomForm.hpp"
#include "../Form/NeedCourseCreationForm.hpp"
#include "../Form/SubscriptionToCourseForm.hpp"

std::shared_ptr<Form> Secretary::CreateForm(FormType aFormType)
{
    switch (aFormType)
	{
		case FormType::CourseFinished: 
            return std::make_shared<CourseFinishedForm>();
        case FormType::NeedMoreClassRoom: 
            return std::make_shared<NeedMoreClassRoomForm>();
        case FormType::NeedCourseCreation: 
            return std::make_shared<NeedCourseCreationForm>();
        case FormType::SubscriptionToCourse: 
            return std::make_shared<SubscriptionToCourseForm>();
        default: 
            return nullptr;
    }
}

void Secretary::ArchiveForm()
{
}
