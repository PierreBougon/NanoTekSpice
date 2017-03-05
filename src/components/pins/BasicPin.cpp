//
// Created by Pierre Bougon on 01/03/17.
//

#include "components/pins/BasicPin.h"

nts::Component::BasicPin::BasicPin() : APin(nts::Component::PinType::basic)
{}

nts::Tristate nts::Component::BasicPin::compute(const nts::IComponent &component)
{
    if (linked)
        return const_cast<APin *>(linked)->compute(component);
    return UNDEFINED;
}

bool nts::Component::BasicPin::link(const nts::Component::APin *toLink)
{
    linked = toLink;
    return true;
}

nts::Tristate nts::Component::BasicPin::getState() const
{
    if (linked)
        return linked->getState();
    return UNDEFINED;
}