//
// Created by Pierre Bougon on 17/02/17.
//

#include "components/pins/CarryOutPin.h"

nts::Component::CarryOutPin::CarryOutPin(const nts::Component::InputPin *inputPin1,
                                         const nts::Component::InputPin *inputPin2)
        : OutputPin(inputPin1, inputPin2)
{
       computedState = FALSE;
}

void nts::Component::CarryOutPin::setState(Tristate state)
{
    computedState = state;
}

nts::Component::CarryOutPin::~CarryOutPin()
{

}

bool nts::Component::CarryOutPin::isCorrectlyLinked()
{
    return true;
}

nts::Tristate nts::Component::CarryOutPin::compute(const nts::IComponent &component)
{
    return getState();
}
