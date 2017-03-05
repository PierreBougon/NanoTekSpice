//
// Created by Pierre Bougon on 06/02/17.
//

#include "exceptions/NonImplemented.h"
#include "components/Cmk4801.h"

nts::Component::Cmk4801::Cmk4801(const std::string &name) : AComponent(name)
{
    throw new nts::Exception::NonImplemented((std::string)name);
}

nts::Tristate nts::Component::Cmk4801::gate(nts::Component::InputPin const *inputPin1,
                                            nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::Cmk4801::~Cmk4801()
{

}
