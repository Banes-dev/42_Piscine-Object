#include "Headmaster.hpp"
#include "../Form/Form.hpp"

void Headmaster::receiveForm(Form* aForm)
{
    if (aForm)
        mFormToValidate.push_back(aForm);
}
