//
// Created by Pierre Bougon on 09/02/17.
//

#include "components/SimpleOutputPin.h"

nts::Component::SimpleOutputPin::SimpleOutputPin()
        : APin(nts::Component::PinType::simpleOutput), pinIt(0)
{}

bool nts::Component::SimpleOutputPin::link(const nts::Component::APin *toLink)
{
    if (toLink->getType() == nts::Component::PinType::output)
    {
        OutputPin const *_toLink = static_cast<OutputPin const *>(toLink);
        listOutputPin.push_back(_toLink);
        return (true);
    }
    return (false);
}

nts::Tristate nts::Component::SimpleOutputPin::compute(const nts::IComponent &component)
{
    (void)component;
    return listOutputPin[pinIt++]->getState();
}

nts::Tristate
nts::Component::SimpleOutputPin::compute(const nts::IComponent &component, size_t it)
{
    (void)component;
    return listOutputPin[it]->getState();
}

nts::Tristate nts::Component::SimpleOutputPin::getState() const
{
    return UNDEFINED;
}
