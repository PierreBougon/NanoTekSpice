//
// Created by Pierre Bougon on 07/02/17.
//

#include "components/InputPin.h"

nts::Tristate nts::Component::InputPin::getState() const
{
    if (inputPin)
        return inputPin->getValue();
    return nts::Tristate::UNDEFINED;
}

nts::Component::InputPin::InputPin(nts::Component::SimpleInputPin *inputPin)
        : inputPin(inputPin)
{}

nts::Component::InputPin::~InputPin()
{
}
