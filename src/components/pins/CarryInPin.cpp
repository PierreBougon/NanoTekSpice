//
// Created by Pierre Bougon on 05/03/17.
//

#include "components/pins/CarryInPin.h"

nts::Component::CarryInPin::CarryInPin() : InputPin(), state(UNDEFINED)
{}

nts::Component::CarryInPin::~CarryInPin()
{

}

void nts::Component::CarryInPin::setState(nts::Tristate _state)
{
    state = _state;
}

nts::Tristate nts::Component::CarryInPin::getState() const
{
    if (state == UNDEFINED)
        return InputPin::getState();
    return state;
}
