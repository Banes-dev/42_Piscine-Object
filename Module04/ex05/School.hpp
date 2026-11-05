#pragma once

#include <vector>
#include <string>
#include <memory>

class Student;
class Professor;
class Course;
class Headmaster;
class Secretary;

class School
{
	private :
		std::shared_ptr<Headmaster> mHeadmaster;
		std::shared_ptr<Secretary> mSecretary;

	public :
		School();
		~School() = default;

		void RunDayRoutine();
		void LaunchClasses();
		void RequestRingBell();

		void RecruteProfessor(std::shared_ptr<Professor> aProf);
		void RecruteStudent(std::shared_ptr<Student> aStudent);

		std::shared_ptr<Course> GetCourse(std::string aName);
		std::vector<std::shared_ptr<Student>> GetStudents();
		std::vector<std::shared_ptr<Professor>> GetProfessors();
		std::shared_ptr<Headmaster> GetHeadmaster();
		std::shared_ptr<Secretary> GetSecretary();

		void GraduationCeremony();
};
