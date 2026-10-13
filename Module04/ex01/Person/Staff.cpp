#include "Staff.hpp"
#include "../Form/Form.hpp"

void Staff::Sign(Form *aForm)
{
    if (aForm)
        aForm->Execute();
}
