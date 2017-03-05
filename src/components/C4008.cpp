//
// Created by Pierre Bougon on 09/02/17.
//

#include "components/pins/CarryOutPin.h"
#include "components/pins/CarryInPin.h"
#include "components/Gates.h"
#include "components/C4008.h"

nts::Component::C4008::C4008(const std::string &name) : AComponent(name)
{
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    pinList.push_back(new InputPin());
    //1-7
    pinList.push_back(new VoidPin());
    //VSS 8
    pinList.push_back(new CarryInPin());
    //Cary IN 9
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[5]),
                                    dynamic_cast<InputPin *>(pinList[6])));
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[3]),
                                    dynamic_cast<InputPin *>(pinList[4])));
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[1]),
                                    dynamic_cast<InputPin *>(pinList[2])));
    //SUM 10-12
    APin *b4 = new InputPin();
    pinList.push_back(new OutputPin(dynamic_cast<InputPin *>(pinList[8]),
                                    dynamic_cast<InputPin *>(b4)));
    //SUM 13
    pinList.push_back(new CarryOutPin());
    // Carry out

    pinList.push_back(b4);
    //15
}

nts::Tristate nts::Component::C4008::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    Tristate sum = Gate::xorGate(inputPin1->getState(), inputPin2->getState());
    Tristate cout = Gate::andGate(inputPin1->getState(), inputPin2->getState());
    Tristate cout2 = Gate::andGate(sum, getCarryInState());
    sum = Gate::xorGate(sum, getCarryInState());
    dynamic_cast<nts::Component::CarryOutPin *>(const_cast<APin *>(getCarryOut()))->setState(
            Gate::orGate(cout, cout2));
    getCarryIn()->setState(getCarryOutState());
    return sum;
}

nts::Component::C4008::~C4008()
{

}

nts::Component::CarryInPin *nts::Component::C4008::getCarryIn() const
{
    return dynamic_cast<CarryInPin *>(const_cast<APin *>(getPinAt(8)));
}

const nts::Component::APin *nts::Component::C4008::getCarryOut() const
{
    return getPinAt(13);
}

nts::Component::APin *nts::Component::C4008::_getCarryOut()
{
    return _getPinAt(13);
}

nts::Tristate nts::Component::C4008::getCarryOutState() const
{
    return getPinAt(13)->getState();
}

nts::Tristate nts::Component::C4008::getCarryInState() const
{
    return getPinAt(8)->getState();
}

void nts::Component::C4008::onSimulationFinished()
{
    getCarryIn()->setState(UNDEFINED);
}
