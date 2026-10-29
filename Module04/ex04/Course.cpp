#include "Course.hpp"
#include "Person/Professor.hpp"
#include "Person/Student.hpp"


void Course::Assign(Professor *aProfessor)
{
	(void)mNumberOfClassToGraduate;
    mResponsable = aProfessor;
}

void Course::Subscribe(Student *aStudent)
{
    if (mStudents.size() < (size_t)mMaximumNumberOfStudent)
        mStudents.push_back(aStudent);
}
