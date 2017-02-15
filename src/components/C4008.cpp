//
// Created by Pierre Bougon on 09/02/17.
//

#include "components/C4008.h"

nts::Tristate nts::Component::C4008::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::C4008::C4008(const std::string &name) : AComponent(name)
{}

nts::Component::C4008::~C4008()
{

}
