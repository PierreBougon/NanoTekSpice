//
// Created by Pierre Bougon on 06/02/17.
//

#include "components/pins/VoidPin.h"
#include "components/Gates.h"
#include "components/pins/OutputPin.h"
#include "components/C4011.h"

nts::Component::C4011::C4011(const std::string &name) : AComponent(name)
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
    pinList.push_back(new VoidPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[7]),
                                    dynamic_cast<InputPin *>(pinList[8])));
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.insert(pinList.begin() + 10,
                   new OutputPin(dynamic_cast<InputPin *>(pinList[10]),
                                 dynamic_cast<InputPin *>(pinList[11])));
}

nts::Tristate nts::Component::C4011::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return (Gate::nandGate(inputPin1->getState(), inputPin2->getState()));
}

nts::Component::C4011::~C4011()
{

}
