#include "NeedMoreClassRoomForm.hpp"

void NeedMoreClassRoomForm::Execute()
{
    if (IsSigned() != true)
    {
        std::cout << "[NeedMoreClassRoomForm]" << " Form is not signed !" << std::endl;
        return;
    }
    auto vNewRoom = std::make_shared<Classroom>();
    RoomList::GetInstance().Add(vNewRoom);
    std::cout << "[NeedMoreClassRoomForm]" << " Classroom " << vNewRoom->GetId() << " created !" << std::endl;
}
