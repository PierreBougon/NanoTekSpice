//
// Created by Pierre Bougon on 07/02/17.
//

#include <components/pins/APin.h>
#include "components/pins/IComponent.h"

nts::Component::APin::APin(nts::Component::PinType type)
        : type(type)
{
}

nts::Component::APin::~APin()
{

}

nts::Component::PinType nts::Component::APin::getType() const
{
    return type;
}