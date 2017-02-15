//
// Created by Pierre Bougon on 14/02/17.
//

#include "components/CFalse.h"

nts::Component::CFalse::CFalse(const std::string &name) : CInput(name)
{
    this->setState(TRUE);
}

nts::Component::CFalse::~CFalse()
{
}
