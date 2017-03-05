//
// Created by Pierre Bougon on 07/02/17.
//

#include "components/pins/OutputPin.h"
#include "exceptions/UndefinedLinkage.h"

nts::Component::OutputPin::OutputPin(const nts::Component::InputPin *inputPin1,
                                     const nts::Component::InputPin *inputPin2)
        : APin(nts::Component::PinType::output),
          inputPin1(inputPin1), inputPin2(inputPin2),
          computedState(nts::Tristate::UNDEFINED)
{}

nts::Component::OutputPin::~OutputPin()
{

}

nts::Tristate nts::Component::OutputPin::compute(IComponent const &component)
{
    if (!inputPin1 || !inputPin2)
        throw new nts::Exception::UndefinedLinkage();
    computedState = component.gate(inputPin1, inputPin2);
    return (computedState);
}

bool nts::Component::OutputPin::link(nts::Component::APin const *pin)
{
    if (pin->getType() != PinType::input)
        return false;
    InputPin const *toLink = static_cast<InputPin const *>(pin);
    if (!inputPin1)
        inputPin1 = toLink;
    else if (!inputPin2)
        inputPin2 = toLink;
    else
        return false;
    return true;
}

const nts::Component::InputPin *nts::Component::OutputPin::getInputPin1() const
{
    return inputPin1;
}

void nts::Component::OutputPin::setInputPin1(const nts::Component::InputPin *inputPin1)
{
    OutputPin::inputPin1 = inputPin1;
}

const nts::Component::InputPin *nts::Component::OutputPin::getInputPin2() const
{
    return inputPin2;
}

void nts::Component::OutputPin::setInputPin2(const nts::Component::InputPin *inputPin2)
{
    OutputPin::inputPin2 = inputPin2;
}

void nts::Component::OutputPin::resetCompute()
{
    computedState = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Component::OutputPin::getState() const
{
    return computedState;
}

bool nts::Component::OutputPin::isCorrectlyLinked()
{
    return inputPin1 && inputPin2;
}
