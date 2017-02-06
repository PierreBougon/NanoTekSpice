//
// Created by Pierre Bougon on 06/02/17.
//

#include <components/AComponent.h>

nts::Component::AComponent::AComponent() : name("UnnamedComponent")
{
}

nts::Component::AComponent::AComponent(const std::string &name) : name(name)
{
}

nts::Component::AComponent::~AComponent()
{
}

const std::string &nts::Component::AComponent::getName() const
{
    return name;
}

void nts::Component::AComponent::setName(const std::string &name)
{
    AComponent::name = name;
}
