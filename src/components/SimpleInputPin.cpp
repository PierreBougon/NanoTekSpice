//
// Created by Pierre Bougon on 07/02/17.
//

#include "components/SimpleInputPin.h"

nts::Component::SimpleInputPin::SimpleInputPin(nts::Tristate state)
        : APin(nts::Component::PinType::simpleInput), state(state)
{}

nts::Component::SimpleInputPin::~SimpleInputPin()
{

}

nts::Tristate nts::Component::SimpleInputPin::compute(IComponent const &component)
{
    (void)component;
    return getState();
}

bool nts::Component::SimpleInputPin::link(nts::Component::APin const *pin)
{
    (void)pin;
    return false;
}

nts::Tristate nts::Component::SimpleInputPin::getState() const
{
    return state;
}

void nts::Component::SimpleInputPin::setState(nts::Tristate state)
{
    SimpleInputPin::state = state;
}
