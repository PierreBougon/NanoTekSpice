//
// Created by Pierre Bougon on 03/02/17.
//

#include "components/ComponentCreator.h"

nts::IComponent *
nts::ComponentCreator::createComponent(const std::string &type, const std::string &value)
{
    switch (std::stoi(type))
    {
        case 2716:
            return create2716(value);
        case 4001:
            return create4001(value);
        case 4008:
            return create4008(value);
        case 4011:
            return create4011(value);
        case 4013:
            return create4013(value);
        case 4017:
            return create4017(value);
        case 4030:
            return create4030(value);
        case 4040:
            return create4040(value);
        case 4069:
            return create4069(value);
        case 4071:
            return create4071(value);
        case 4081:
            return create4081(value);
        case 4094:
            return create4094(value);
        case 4503:
            return create4503(value);
        case 4512:
            return create4512(value);
        case 4514:
            return create4514(value);
        case 4004:
            return createi4004(value);
        case 4801:
            return createmk4801(value);
        default:
            return nullptr;
    }
}

nts::IComponent *nts::ComponentCreator::create2716(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4001(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4008(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4011(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4013(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4017(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4030(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4040(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4069(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4071(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4081(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4094(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4503(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4512(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::create4514(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::createi4004(const std::string &value) const
{
    return nullptr;
}

nts::IComponent *nts::ComponentCreator::createmk4801(const std::string &value) const
{
    return nullptr;
}
