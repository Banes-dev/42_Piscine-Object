#include <iostream>
#include <memory>
#include "Color.hpp"
#include "School.hpp"
#include "Person/Student.hpp"
#include "Person/Professor.hpp"
#include "Course.hpp"

int main()
{
	std::cout << Cyan << "=== Exercice 05 : Facade (School) ===" << Reset_Color << std::endl;

	School vSchool;

	std::cout << Yellow << "\n--- 1. Recrutement des professeurs et etudiants ---" << Reset_Color << std::endl;
	std::shared_ptr<Professor> vProfSnape = std::make_shared<Professor>("Severus Snape");
	std::shared_ptr<Student> vStudentHarry = std::make_shared<Student>("Harry Potter");

	vSchool.RecruteProfessor(vProfSnape);
	vSchool.RecruteStudent(vStudentHarry);

	std::cout << Yellow << "\n--- 2. Creation du cours et inscription ---" << Reset_Color << std::endl;
	vProfSnape->AskForNewCourse("Potions 101");
	std::shared_ptr<Course> vPotions = vSchool.GetCourse("Potions 101");

	if (vPotions)
	{
		vProfSnape->AssignCourse(vPotions.get());
		vStudentHarry->AskToJoinCourse(vPotions.get());
	}

	std::cout << Yellow << "\n--- 3. Execution de la routine de la journee ---" << Reset_Color << std::endl;
	vSchool.RunDayRoutine();

	std::cout << Yellow << "\n--- 4. Ceremonie de remise des diplomes ---" << Reset_Color << std::endl;
	vSchool.GraduationCeremony();

	return 0;
}
