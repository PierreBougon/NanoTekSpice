//
// Created by Pierre Bougon on 01/03/17.
//

#include "components/pins/BasicOutputPin.h"

nts::Component::BasicOutputPin::BasicOutputPin()
        : BasicPin(), state(UNDEFINED), prevState(UNDEFINED)
{
    
}

void nts::Component::BasicOutputPin::setState(Tristate _state)
{
    prevState = state;
    state = _state;
}

nts::Tristate nts::Component::BasicOutputPin::getState() const
{
    return state;
}

nts::Tristate nts::Component::BasicOutputPin::getPrevState() const
{
    return prevState;
}
