//
// Created by Pierre Bougon on 06/02/17.
//

#include <components/OutputPin.h>
#include <components/Gates.h>
#include "components/C4001.h"

nts::Component::C4001::C4001(const std::string &name) : AComponent(name)
{
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[0]),
                                    dynamic_cast<InputPin *>(pinList[1])));
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.insert(pinList.begin() + 3,
                   new OutputPin(dynamic_cast<InputPin *>(pinList[3]),
                                 dynamic_cast<InputPin *>(pinList[4])));
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[6]),
                                    dynamic_cast<InputPin *>(pinList[7])));
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[9]),
                                    dynamic_cast<InputPin *>(pinList[10])));

}

nts::Tristate nts::Component::C4001::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return Gate::norGate(inputPin1->getState(), inputPin2->getState());
}

nts::Component::C4001::~C4001()
{

}
