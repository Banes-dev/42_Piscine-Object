#include <iostream>
#include <memory>
#include "Color.hpp"
#include "Singletons.hpp"
#include "Person/Headmaster.hpp"
#include "Person/Student.hpp"
#include "Person/Professor.hpp"

int main()
{
    std::cout << Cyan << "--- Exercice 04 : Observer Pattern (La Cloche) ---" << Reset_Color << std::endl;

    auto headmaster = std::make_shared<Headmaster>("Albus Dumbledore");
    auto profSnape = std::make_shared<Professor>("Severus Snape");
    auto studentHarry = std::make_shared<Student>("Harry Potter");
    auto studentRon = std::make_shared<Student>("Ron Weasley");

    headmaster->SubscribeBell(profSnape.get());
    headmaster->SubscribeBell(studentHarry.get());
    headmaster->SubscribeBell(studentRon.get());

    std::cout << Green << "\n--- 10h00 : Debut de la recreation ---" << Reset_Color << std::endl;
    headmaster->RingBell();

    std::cout << Green << "\n--- 10h15 : Fin de la recreation ---" << Reset_Color << std::endl;
    headmaster->RingBell();

    return 0;
}
