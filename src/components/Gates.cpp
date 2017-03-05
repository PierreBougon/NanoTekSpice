//
// Created by Pierre Bougon on 16/02/17.
//

#include "components/Gates.h"

nts::Tristate nts::Gate::xorGate(nts::Tristate a, nts::Tristate b)
{
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    if ((a == TRUE && b == FALSE)
        || (a == FALSE && b == TRUE))
        return TRUE;
    return FALSE;
}

nts::Tristate nts::Gate::norGate(nts::Tristate a, nts::Tristate b)
{
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    if (a == FALSE && b == FALSE)
        return TRUE;
    return FALSE;
}

nts::Tristate nts::Gate::nandGate(Tristate a, Tristate b)
{
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    return (nts::Tristate::TRUE);
}

nts::Tristate nts::Gate::andGate(Tristate a, Tristate b)
{
    if (a == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);

    if (a == nts::Tristate::UNDEFINED
        || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);

    if (a == nts::Tristate::TRUE
        && b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);

    return (nts::Tristate::FALSE);
}

nts::Tristate nts::Gate::orGate(Tristate a, Tristate b)
{
    if (a == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);

    if (a == nts::Tristate::UNDEFINED
        || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);

    if (b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);

    return (nts::Tristate::FALSE);
}
