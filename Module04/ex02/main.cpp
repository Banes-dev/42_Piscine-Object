#include <iostream>
#include <memory>

#include "Color.hpp"
#include "Singletons.hpp"
#include "Person/Secretary.hpp"
#include "Person/Headmaster.hpp"
#include "Person/Student.hpp"
#include "Course.hpp"
#include "Form/SubscriptionToCourseForm.hpp"
#include "Form/NeedCourseCreationForm.hpp"

int main()
{
    std::cout << Cyan << "--- Exercise 02 : Factory and Command ---" << Reset_Color << std::endl;

    // Init actors
    auto secretary = std::make_shared<Secretary>("Peggy");
    auto headmaster = std::make_shared<Headmaster>("Albus Dumbledore");
    auto student = std::make_shared<Student>("Harry");
    auto potionsCourse = std::make_shared<Course>("Potions 101");

    CourseList::GetInstance().Add(potionsCourse);

    std::cout << "\n" << Yellow << Arrow_right << " Step 1 : Secretary creates a subscription form" << Reset_Color << std::endl;
    
    std::shared_ptr<Form> rawForm = secretary->CreateForm(FormType::SubscriptionToCourse);
    auto subForm = std::dynamic_pointer_cast<SubscriptionToCourseForm>(rawForm);
    
    if (subForm)
	{
        std::cout << "Filling form with student and course..." << std::endl;
        subForm->Fill(student, potionsCourse);
    }

    std::cout << "\n" << Red << Arrow_right << " Step 2 : Attempt execution WITHOUT signature" << Reset_Color << std::endl;
    
    // Should fail
    subForm->Execute();

    std::cout << "\n" << Green << Arrow_right << " Step 3 : Headmaster signs and executes the form" << Reset_Color << std::endl;
    
    subForm->Sign();
    subForm->Execute();

    std::cout << "\n" << Yellow << Arrow_right << " Step 4 : Test course creation" << Reset_Color << std::endl;
    
    auto rawCourseForm = secretary->CreateForm(FormType::NeedCourseCreation);
    auto courseForm = std::dynamic_pointer_cast<NeedCourseCreationForm>(rawCourseForm);
    
    if (courseForm) {
        courseForm->Fill("Defense Against the Dark Arts");
        
        std::cout << Red << "[Unsigned] -> " << Reset_Color;
        courseForm->Execute();

        courseForm->Sign();
        std::cout << Green << "[Signed] -> " << Reset_Color;
        courseForm->Execute();
    }

    std::cout << "\n" << Blue << "Global check :" << Reset_Color << std::endl;
    std::cout << "Number of courses in Singleton = " << White << CourseList::GetInstance().Get().size() << Reset_Color << " (expected : 2)" << std::endl;

    return 0;
}
