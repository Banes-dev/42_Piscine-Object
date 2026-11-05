#include "School.hpp"
#include "Singletons.hpp"
#include "Person/Headmaster.hpp"
#include "Person/Secretary.hpp"
#include "Person/Student.hpp"
#include "Person/Professor.hpp"
#include "Course.hpp"
#include "Color.hpp"
#include <iostream>

School::School()
{
	mHeadmaster = std::make_shared<Headmaster>("Albus Dumbledore");
	mSecretary = std::make_shared<Secretary>("Peggy");

	mHeadmaster->AssignSecretary(mSecretary);

	StaffList::GetInstance().Add(mHeadmaster);
	StaffList::GetInstance().Add(mSecretary);
}

void School::RunDayRoutine()
{
	std::cout << Cyan << "=== Starting Day Routine ===" << Reset_Color << std::endl;

	// 1. launch classes
	LaunchClasses();

	// 2. allow student and professor to go on recreation
	std::cout << Yellow << "\n--- Morning Recreation ---" << Reset_Color << std::endl;
	RequestRingBell(); // Start of break
	RequestRingBell(); // End of break

	// 3. launch classes
	LaunchClasses();

	// 4. launch lunch
	std::cout << Yellow << "\n--- Lunch Break ---" << Reset_Color << std::endl;

	// 5. launch classes
	LaunchClasses();

	// 6. allow student and professor to go on recreation
	std::cout << Yellow << "\n--- Afternoon Recreation ---" << Reset_Color << std::endl;
	RequestRingBell(); // Start of break
	RequestRingBell(); // End of break

	// 7. launch classes
	LaunchClasses();
}

void School::LaunchClasses()
{
	std::cout << Green << "\n[School] " << Reset_Color << "Headmaster asks professors and students to attend classes." << std::endl;
	for (auto vProf : GetProfessors())
	{
		if (vProf)
			vProf->DoClass();
	}
}

void School::RequestRingBell()
{
	if (mHeadmaster)
		mHeadmaster->RingBell();
}

void School::RecruteProfessor(std::shared_ptr<Professor> aProf)
{
	if (aProf)
	{
		aProf->AssignHeadmaster(mHeadmaster.get());
		mHeadmaster->SubscribeBell(aProf.get());
		StaffList::GetInstance().Add(aProf);
	}
}

void School::RecruteStudent(std::shared_ptr<Student> aStudent)
{
	if (aStudent)
	{
		aStudent->AssignHeadmaster(mHeadmaster.get());
		mHeadmaster->SubscribeBell(aStudent.get());
		StudentList::GetInstance().Add(aStudent);
	}
}

std::shared_ptr<Course> School::GetCourse(std::string aName)
{
	for (auto vCourse : CourseList::GetInstance().Get())
	{
		if (vCourse && vCourse->GetName() == aName)
			return vCourse;
	}
	return nullptr;
}

std::vector<std::shared_ptr<Student>> School::GetStudents()
{
	return StudentList::GetInstance().Get();
}

std::vector<std::shared_ptr<Professor>> School::GetProfessors()
{
	std::vector<std::shared_ptr<Professor>> vProfs;
	for (auto vStaff : StaffList::GetInstance().Get())
	{
		std::shared_ptr<Professor> vProf = std::dynamic_pointer_cast<Professor>(vStaff);
		if (vProf)
			vProfs.push_back(vProf);
	}
	return vProfs;
}

std::shared_ptr<Headmaster> School::GetHeadmaster()
{
	return mHeadmaster;
}

std::shared_ptr<Secretary> School::GetSecretary()
{
	return mSecretary;
}

void School::GraduationCeremony()
{
	std::cout << Purple << "\n[School] Starting Graduation Ceremony!" << Reset_Color << std::endl;
	for (auto vProf : GetProfessors())
	{
		for (auto vStudent : GetStudents())
		{
			if (vProf && vStudent)
				vProf->ProposeGraduation(vStudent.get());
		}
	}
}
