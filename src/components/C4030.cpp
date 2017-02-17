//
// Created by Pierre Bougon on 06/02/17.
//

#include <components/OutputPin.h>
#include "components/C4030.h"

nts::Component::C4030::C4030(const std::string &name) : AComponent(name)
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

nts::Tristate nts::Component::C4030::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    if (inputPin1->getState() == UNDEFINED || inputPin2->getState() == UNDEFINED)
        return UNDEFINED;
    if ((inputPin1->getState() == TRUE && inputPin2->getState() == FALSE)
            || (inputPin1->getState() == FALSE && inputPin2->getState() == TRUE))
        return TRUE;
    return FALSE;
}

nts::Component::C4030::~C4030()
{

}
