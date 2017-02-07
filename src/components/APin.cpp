//
// Created by Pierre Bougon on 07/02/17.
//

#include "components/APin.h"

nts::Component::APin::APin(nts::Component::PinType type, nts::Tristate value)
        : type(type), value(value)
{
}

nts::Component::APin::~APin()
{

}

nts::Component::PinType nts::Component::APin::getType() const
{
    return type;
}

nts::Tristate nts::Component::APin::getValue() const
{
    return value;
}

void nts::Component::APin::setValue(nts::Tristate value)
{
    APin::value = value;
}
