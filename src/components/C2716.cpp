//
// Created by Pierre Bougon on 09/02/17.
//

#include "components/C2716.h"

nts::Tristate nts::Component::C2716::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::C2716::C2716(const std::string &name) : AComponent(name)
{}
