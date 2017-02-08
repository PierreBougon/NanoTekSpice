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

nts::Tristate nts::Component::AComponent::Compute(size_t pin_num_this)
{
    return nts::Tristate::UNDEFINED;
}

void nts::Component::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component,
                                         size_t pin_num_target)
{

}

void nts::Component::AComponent::Dump(void) const
{

}
