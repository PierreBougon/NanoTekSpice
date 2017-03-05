//
// Created by Pierre Bougon on 06/02/17.
//

#include "exceptions/NonImplemented.h"
#include "components/C4017.h"

nts::Component::C4017::C4017(const std::string &name) : AComponent(name)
{
    (void)pinList;
    throw new nts::Exception::NonImplemented((std::string)name);
}

nts::Tristate nts::Component::C4017::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    (void)inputPin1;
    (void)inputPin2;
    return UNDEFINED;
}

nts::Component::C4017::~C4017()
{

}
