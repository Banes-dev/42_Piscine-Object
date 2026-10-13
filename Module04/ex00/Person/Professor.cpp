#include "Professor.hpp"
#include "../Course.hpp"

void Professor::AssignCourse(Course *aCourse)
{
    mCurrentCourse = aCourse;
}

void Professor::DoClass()
{
}

void Professor::CloseCourse()
{
    mCurrentCourse = nullptr;
}
