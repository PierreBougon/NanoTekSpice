//
// Created by Pierre Bougon on 06/02/17.
//

#include "components/C4081.h"

nts::Component::C4081::C4081(const std::string &name) : AComponent(name)
{}

nts::Tristate nts::Component::C4081::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}
