//
// Created by Pierre Bougon on 06/02/17.
//

#include <components/OutputPin.h>
#include "components/C4071.h"

nts::Component::C4071::C4071(const std::string &name) : AComponent(name)
{
    InputPin inputPin;

    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[0]),
                                    dynamic_cast<InputPin *>(pinList[1])));
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[3]),
                                dynamic_cast<InputPin *>(pinList[4])));
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[6]),
                                dynamic_cast<InputPin *>(pinList[7])));
}

nts::Tristate nts::Component::C4071::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    if (inputPin1->getState() == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);

    if (inputPin1->getState() == nts::Tristate::UNDEFINED
        || inputPin2->getState() == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);

    if (inputPin1->getState() == nts::Tristate::TRUE
        && inputPin2->getState() == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);

    return (nts::Tristate::FALSE);
}

nts::Component::C4071::~C4071()
{

}
