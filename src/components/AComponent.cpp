//
// Created by Pierre Bougon on 06/02/17.
//

#include "components/AComponent.h"
#include "utils/Logger.h"

nts::Component::AComponent::AComponent(const std::string &name) : name(name)
{
}

nts::Component::AComponent::~AComponent()
{
    for (std::vector<APin *>::iterator it = pinList.begin(); it != pinList.end(); ++it)
        delete(*it);
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
    return _getPinAt(pin_num_this)->compute(*this);
}

void nts::Component::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component,
                                         size_t pin_num_target)
{
    //TODO : throw better exception
    AComponent const &aComponent = static_cast<AComponent const &>(component);
    if (!pinList[pin_num_this]->link(aComponent.getPinAt(pin_num_target)))
        throw std::exception();
}

void nts::Component::AComponent::Dump(void) const
{
    Logger::log(Logger::Info, "## Component: " + name + "\n");
    for (int i = 0; i < nbPin; ++i)
    {
        switch (pinList[i]->getState())
        {
            case nts::Tristate::FALSE:
                Logger::log(Logger::Info, "Pin " + std::to_string(i) + ": FALSE");
                break;
            case nts::Tristate::TRUE:
                Logger::log(Logger::Info, "Pin " + std::to_string(i) + ": TRUE");
                break;
            case nts::Tristate::UNDEFINED:
                Logger::log(Logger::Info, "Pin " + std::to_string(i) + ": UNDEFINED");
                break;
            default:
                break;
        }
    }
    Logger::log(Logger::Info, "-----------------");
}

const nts::Component::APin
*nts::Component::AComponent::getPinAt(size_t pin_num_this) const
{
    return pinList[pin_num_this];
}

nts::Component::APin *nts::Component::AComponent::_getPinAt(size_t pin_num_this)
{
    return pinList[pin_num_this];
}

void nts::Component::AComponent::onSimulationFinished()
{}

nts::Tristate nts::Component::AComponent::getStateAt(size_t pin_num_this) const
{
    return getPinAt(pin_num_this)->getState();
}
