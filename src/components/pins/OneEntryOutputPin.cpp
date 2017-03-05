//
// Created by Pierre Bougon on 27/02/17.
//

#include "components/pins/OneEntryOutputPin.h"

nts::Component::OneEntryOutputPin::OneEntryOutputPin(
        const nts::Component::InputPin *inputPin) : OutputPin(inputPin, nullptr)
{}

nts::Component::OneEntryOutputPin::~OneEntryOutputPin()
{

}

nts::Tristate nts::Component::OneEntryOutputPin::compute(const nts::IComponent &component)
{
    //TODO : throw better exception
    if (!getInputPin1())
        throw new std::bad_alloc();
    computedState = component.gate(getInputPin1(), nullptr);
    return (computedState);
}

bool nts::Component::OneEntryOutputPin::link(const nts::Component::APin *pin)
{
    if (pin->getType() != PinType::input)
        return false;
    InputPin const *toLink = static_cast<InputPin const *>(pin);
    if (!getInputPin1())
    {
        setInputPin1(toLink);
        return true;
    }
    else
        return false;
}

const nts::Component::InputPin *nts::Component::OneEntryOutputPin::getInputPin() const
{
    return getInputPin1();
}

void
nts::Component::OneEntryOutputPin::setInputPin(const nts::Component::InputPin *inputPin)
{
    setInputPin1(inputPin);
}

const nts::Component::InputPin *nts::Component::OneEntryOutputPin::getInputPin2() const
{
    return OutputPin::getInputPin2();
}

void
nts::Component::OneEntryOutputPin::setInputPin2(const nts::Component::InputPin *inputPin2)
{
    OutputPin::setInputPin2(inputPin2);
}

const nts::Component::InputPin *nts::Component::OneEntryOutputPin::getInputPin1() const
{
    return OutputPin::getInputPin1();
}

void
nts::Component::OneEntryOutputPin::setInputPin1(const nts::Component::InputPin *inputPin1)
{
    OutputPin::setInputPin1(inputPin1);
}
