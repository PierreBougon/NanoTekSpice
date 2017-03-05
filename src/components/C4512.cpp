//
// Created by Pierre Bougon on 06/02/17.
//

#include "exceptions/NonImplemented.h"
#include "components/C4512.h"

nts::Component::C4512::C4512(const std::string &name) : AComponent(name)
{
    throw new nts::Exception::NonImplemented((std::string)name);
}

nts::Tristate nts::Component::C4512::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::C4512::~C4512()
{

}
