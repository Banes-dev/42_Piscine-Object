#include "Room.hpp"
#include "../Person/Person.hpp"

bool Room::CanEnter(Person *aPerson)
{
	(void)mId;
    (void)aPerson;
    return true;
}

void Room::Enter(Person *aPerson)
{
    if (aPerson && CanEnter(aPerson))
        mOccupants.push_back(aPerson);
}

void Room::Exit(Person *aPerson)
{
    for (std::vector<Person *>::iterator it = mOccupants.begin(); it != mOccupants.end(); ++it) {
        if (*it == aPerson) {
            mOccupants.erase(it);
            break;
        }
    }
}

void Room::PrintOccupant() 
{
    std::cout << "Occupants : " << mOccupants.size() << std::endl;
}
