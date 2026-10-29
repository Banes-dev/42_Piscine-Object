#include <iostream>
#include <memory>
#include "Color.hpp"
#include "Singletons.hpp"
#include "Person/Secretary.hpp"
#include "Person/Headmaster.hpp"
#include "Person/Student.hpp"
#include "Person/Professor.hpp"
#include "Course.hpp"

int main()
{
    std::cout << Cyan << "--- Exercice 03 : Mediator ---" << Reset_Color << std::endl;

    // 1. Instanciation des acteurs
    auto secretary = std::make_shared<Secretary>("Peggy");
    auto headmaster = std::make_shared<Headmaster>("Albus Dumbledore");
    
    // On relie la Secrétaire au Headmaster (Médiateur)
    headmaster->AsssignSecretary(secretary);

    auto profSnape = std::make_shared<Professor>("Severus Snape");
    auto studentHarry = std::make_shared<Student>("Harry Potter");

    // On relie le Professeur et l'Étudiant au Headmaster (Médiateur)
	profSnape->AssignHeadmaster(headmaster.get());
	studentHarry->AssignHeadmaster(headmaster.get());

    // Ajout dans les Singletons pour le suivi
    StaffList::GetInstance().Add(headmaster);
    StaffList::GetInstance().Add(secretary);
    StaffList::GetInstance().Add(profSnape);
    StudentList::GetInstance().Add(studentHarry);

    std::cout << "\n" << Yellow << "--- Scenario 1 : Le professeur demande un nouveau cours ---" << Reset_Color << std::endl;
    // Le professeur interagit UNIQUEMENT avec le Headmaster, sans connaître la Secretary ni les Forms[cite: 13]
    profSnape->AskForNewCourse("Potions 101");

    // Récupération du cours créé magiquement dans le Singleton (pour la suite de la simulation)
    std::shared_ptr<Course> potionsCourse = nullptr;
    if (!CourseList::GetInstance().Get().empty())
	{
        potionsCourse = CourseList::GetInstance().Get().back();
        profSnape->AssignCourse(potionsCourse.get());
    }

    std::cout << "\n" << Yellow << "--- Scenario 2 : Le professeur n'a pas de salle ---" << Reset_Color << std::endl;
    // Le professeur demande au Headmaster de créer une salle[cite: 15]
    profSnape->AskForNewRoom();

    std::cout << "\n" << Yellow << "--- Scenario 3 : L'etudiant veut s'inscrire au cours ---" << Reset_Color << std::endl;
    if (potionsCourse) {
        // L'étudiant interagit UNIQUEMENT avec le Headmaster[cite: 14]
        studentHarry->AskToJoinCourse(potionsCourse.get());
    }

    std::cout << "\n" << Yellow << "--- Scenario 4 : L'etudiant a fini le cours ---" << Reset_Color << std::endl;
    // Le professeur prévient le Headmaster que l'étudiant est prêt à être diplômé[cite: 13]
    profSnape->ProposeGraduation(studentHarry.get());

    return 0;
}
