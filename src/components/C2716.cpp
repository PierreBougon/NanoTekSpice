//
// Created by Pierre Bougon on 09/02/17.
//

#include "exceptions/NonImplemented.h"
#include "components/C2716.h"

nts::Tristate nts::Component::C2716::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    (void)inputPin1;
    (void)inputPin2;
    return UNDEFINED;
}

nts::Component::C2716::C2716(const std::string &name) : AComponent(name)
{
    (void)pinList;
    throw new nts::Exception::NonImplemented((std::string)name);
}

nts::Component::C2716::~C2716()
{

}
