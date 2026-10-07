#include <iostream>

#include "Color.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main()
{
	try 
	{
		std::cout << "\n--- 1. CREATION DES OBJETS ---" << std::endl;
		Position pos = {0, 0, 0};
		Statistic stat = {1, 0};
		
		Worker bob(pos, stat);
		Worker alice(pos, stat);
		
		Shovel myShovel;
		Hammer myHammer;

		Workshop shovelWorkshop(TOOL_SHOVEL);
		Workshop hammerWorkshop(TOOL_HAMMER);

		std::cout << "\n--- 2. TEST INSCRIPTION SANS OUTIL (BONUS) ---" << std::endl;
		try {
			shovelWorkshop.AddWorker(&bob);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "\n--- 3. ATTRIBUTION DES OUTILS ET INSCRIPTION ---" << std::endl;
		bob.AddTool(&myShovel);
		alice.AddTool(&myHammer);
		
		shovelWorkshop.AddWorker(&bob);
		hammerWorkshop.AddWorker(&alice);

		std::cout << "\n--- 4. JOURNEE DE TRAVAIL ---" << std::endl;
		shovelWorkshop.ExecuteWorkDay();
		hammerWorkshop.ExecuteWorkDay();

		// Utilisation directe des outils (Test du template Bonus)
		Shovel* bobsTool = bob.GetTool<Shovel>();
		if (bobsTool)
			bobsTool->use();

		std::cout << "\n--- 5. TEST VOL D'OUTIL ---" << std::endl;
		alice.AddTool(&myShovel);
		
		std::cout << "\n--- 6. DESTRUCTION ---" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
