//
// Created by Pierre Bougon on 06/02/17.
//

#include "components/C4001.h"

nts::Component::C4001::C4001(const std::string &name) : AComponent(name)
{}

nts::Tristate nts::Component::C4001::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::C4001::~C4001()
{

}
