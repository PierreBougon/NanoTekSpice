//
// Created by Pierre Bougon on 13/02/17.
//

#include <components/pins/SimpleOutputPin.h>
#include <utils/Logger.h>
#include <stdexcept>
#include "components/COutput.h"


nts::Component::COutput::COutput(const std::string &name) : AComponent(
        name)
{
    pinList.push_back(new SimpleOutputPin());
}

nts::Tristate
nts::Component::COutput::gate(nts::Component::InputPin const *inputPin1,
                                      nts::Component::InputPin const *inputPin2) const
{
    Logger::log(Logger::Warning, "Gate called on a non logical component");
    return (UNDEFINED);
}

nts::Component::COutput::~COutput()
{

}

void nts::Component::COutput::onSimulationFinished()
{
    dynamic_cast<SimpleOutputPin *>(pinList[0])->reset();
}
