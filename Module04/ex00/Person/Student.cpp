#include "Student.hpp"
#include "../Room/Classroom.hpp"
#include "../Course.hpp"


void Student::AttendClass(Classroom *aClassroom)
{
    if (aClassroom)
        aClassroom->Enter(this);
}

void Student::ExitClass()
{
    if (mCurrentRoom)
        mCurrentRoom->Exit(this);
}

void Student::Graduate(Course *aCourse)
{
    (void)aCourse; 
}