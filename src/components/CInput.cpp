//
// Created by Pierre Bougon on 13/02/17.
//

#include <utils/Logger.h>
#include "components/CInput.h"

nts::Component::CInput::CInput(const std::string &name) : AComponent(name)
{
    pinList.push_back(new SimpleInputPin());
}

nts::Tristate
nts::Component::CInput::gate(nts::Component::InputPin const *inputPin1,
                                     nts::Component::InputPin const *inputPin2) const
{
    Logger::log(Logger::Warning, "Gate called on a non logical component");
    return (UNDEFINED);
}

void nts::Component::CInput::setState(Tristate state)
{
    static_cast<SimpleInputPin *>(pinList[0])->setState(state);
}

nts::Tristate nts::Component::CInput::getState() const
{
    return pinList[0]->getState();
}

nts::Component::CInput::~CInput()
{

}
