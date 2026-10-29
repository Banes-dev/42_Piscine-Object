#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "../Form/Form.hpp"
#include "../Form/CourseFinishedForm.hpp"
#include "../Form/NeedCourseCreationForm.hpp"
#include "../Form/SubscriptionToCourseForm.hpp"
#include "../Form/NeedMoreClassRoomForm.hpp"

#include <iostream>
#include <memory>
#include "../Color.hpp"

void Headmaster::ReceiveForm(Form* aForm)
{
    if (aForm)
        mFormToValidate.push_back(aForm);
}

// Secretary
void Headmaster::AsssignSecretary(std::shared_ptr<Secretary> aSecretary)
{
    mSecretary = aSecretary;
}

// Mediator
void Headmaster::RequestGraduation(Student *aStudent, Course *aCourse)
{
    if (mSecretary == nullptr)
    {
        throw SecretaryNotAssignedException();
        return;
    }

    std::shared_ptr<Form> vBaseForm = mSecretary->CreateForm(FormType::CourseFinished);
    std::shared_ptr<CourseFinishedForm> vForm = std::dynamic_pointer_cast<CourseFinishedForm>(vBaseForm);
	// std
    if (vForm)
    {
        vForm->Fill(aStudent, aCourse);
        vForm->Sign();
        vForm->Execute();
    }
}

void Headmaster::RequestCourseCreation(std::string aCourseName)
{
    if (mSecretary == nullptr)
    {
        throw SecretaryNotAssignedException();
        return;
    }

    std::shared_ptr<Form> vBaseForm = mSecretary->CreateForm(FormType::NeedCourseCreation);
    std::shared_ptr<NeedCourseCreationForm> vForm = std::dynamic_pointer_cast<NeedCourseCreationForm>(vBaseForm);
    if (vForm)
    {
        vForm->Fill(aCourseName);
        vForm->Sign();
        vForm->Execute();
    }
}

void Headmaster::RequestCourseSubscription(Student *aStudent, Course *aCourse)
{
    if (mSecretary == nullptr)
    {
        throw SecretaryNotAssignedException();
        return;
    }

    std::shared_ptr<Form> vBaseForm = mSecretary->CreateForm(FormType::SubscriptionToCourse);
    std::shared_ptr<SubscriptionToCourseForm> vForm = std::dynamic_pointer_cast<SubscriptionToCourseForm>(vBaseForm);
    if (vForm)
    {
        vForm->Fill(aStudent, aCourse);
        vForm->Sign();
        vForm->Execute();
    }
}

void Headmaster::RequestRoomCreation()
{
    if (mSecretary)
    {
        std::shared_ptr<Form> vBaseForm = mSecretary->CreateForm(FormType::NeedMoreClassRoom);
        std::shared_ptr<NeedMoreClassRoomForm> vForm = std::dynamic_pointer_cast<NeedMoreClassRoomForm>(vBaseForm);

        if (vForm)
        {
            vForm->Sign();
            vForm->Execute();
        }
    }
}

void Headmaster::SubscribeBell(IObserver *aObserver)
{
	mObservers.push_back(aObserver);
}

void Headmaster::RingBell()
{
	std::cout << "[Headmaster]" << " Ringing the bell" << std::endl;
	for (auto iObserver : mObservers)
		iObserver->Notify(Event::RingBell);
}
