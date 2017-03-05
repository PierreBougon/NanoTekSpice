//
// Created by Pierre Bougon on 06/02/17.
//

#include "exceptions/NonImplemented.h"
#include "components/Ci4004.h"

nts::Component::Ci4004::Ci4004(const std::string &name) : AComponent(name)
{
    throw new nts::Exception::NonImplemented((std::string)name);
}

nts::Tristate nts::Component::Ci4004::gate(nts::Component::InputPin const *inputPin1,
                                           nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::Ci4004::~Ci4004()
{

}
