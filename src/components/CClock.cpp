//
// Created by Pierre Bougon on 15/02/17.
//

#include "components/CClock.h"

nts::Component::CClock::CClock(const std::string &name) : CInput(name)
{}

void nts::Component::CClock::onSimulationFinished()
{
    Tristate state = getPinAt(0)->getState();

    if (state == TRUE)
        setState(FALSE);
    else if (state == FALSE)
        setState(TRUE);
}
