//
// Created by Pierre Bougon on 07/02/17.
//

#include <typeinfo>
#include "components/pins/InputPin.h"

nts::Component::InputPin::InputPin(nts::Component::SimpleInputPin const *inputPin)
        : APin(nts::Component::PinType::input), inputPin(inputPin)
{}

nts::Component::InputPin::~InputPin()
{
}

nts::Tristate nts::Component::InputPin::getState() const
{
    if (inputPin)
        return inputPin->getState();
    return nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Component::InputPin::compute(IComponent const &component)
{
    (void)component;
    return getState();
}

bool nts::Component::InputPin::link(nts::Component::APin const *pin)
{
    if (pin->getType() == nts::Component::PinType::simpleInput
            || pin->getType() == nts::Component::PinType::output
            || pin->getType() == nts::Component::PinType::simpleOutput)
    {
        this->inputPin = static_cast<SimpleInputPin *>(
                const_cast<nts::Component::APin *>(pin));
        return true;
    }
    return false;
}

const nts::Component::SimpleInputPin *nts::Component::InputPin::getInputPin() const
{
    return inputPin;
}

void nts::Component::InputPin::setInputPin(const nts::Component::SimpleInputPin *inputPin)
{
    InputPin::inputPin = inputPin;
}
