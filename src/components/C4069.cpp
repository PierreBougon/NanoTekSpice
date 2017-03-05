//
// Created by Pierre Bougon on 06/02/17.
//

#include "components/pins/VoidPin.h"
#include "components/pins/OneEntryOutputPin.h"
#include "components/Gates.h"
#include "components/C4069.h"

nts::Component::C4069::C4069(const std::string &name) : AComponent(name)
{
    InputPin *tmp;

    pinList.push_back(new InputPin());
    pinList.push_back(new OneEntryOutputPin(dynamic_cast<InputPin *>(pinList[0])));
    pinList.push_back(new InputPin());
    pinList.push_back(new OneEntryOutputPin(dynamic_cast<InputPin *>(pinList[2])));
    pinList.push_back(new InputPin());
    pinList.push_back(new OneEntryOutputPin(dynamic_cast<InputPin *>(pinList[4])));
    pinList.push_back(new VoidPin());
    tmp = new InputPin();
    pinList.push_back(new OneEntryOutputPin(tmp));
    pinList.push_back(tmp);
    tmp = new InputPin();
    pinList.push_back(new OneEntryOutputPin(tmp));
    pinList.push_back(tmp);
    tmp = new InputPin();
    pinList.push_back(new OneEntryOutputPin(tmp));
    pinList.push_back(tmp);
}

nts::Tristate nts::Component::C4069::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return nts::Gate::invertGate(inputPin1->getState());
}

nts::Component::C4069::~C4069()
{}
