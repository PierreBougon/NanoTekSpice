//
// Created by Pierre Bougon on 03/02/17.
//

#include <Logger.h>
#include "components/ComponentCreator.h"

nts::ComponentCreator::ComponentCreator()
{
    creationTab["2716"] = &ComponentCreator::create2716;
    creationTab["4001"] = &ComponentCreator::create4001;
    creationTab["4008"] = &ComponentCreator::create4008;
    creationTab["4011"] = &ComponentCreator::create4011;
    creationTab["4013"] = &ComponentCreator::create4013;
    creationTab["4017"] = &ComponentCreator::create4017;
    creationTab["4030"] = &ComponentCreator::create4030;
    creationTab["4040"] = &ComponentCreator::create4040;
    creationTab["4069"] = &ComponentCreator::create4069;
    creationTab["4071"] = &ComponentCreator::create4071;
    creationTab["4081"] = &ComponentCreator::create4081;
    creationTab["4094"] = &ComponentCreator::create4094;
    creationTab["4503"] = &ComponentCreator::create4503;
    creationTab["4512"] = &ComponentCreator::create4512;
    creationTab["4514"] = &ComponentCreator::create4514;
    creationTab["i4004"] = &ComponentCreator::createi4004;
    creationTab["mk4801"] = &ComponentCreator::createmk4801;
}

nts::IComponent *nts::ComponentCreator::createComponent(const std::string &type,
                                                        const std::string &value) const
{
    if (creationTab.find(type) == creationTab.end())
    {
        Logger::log(Logger::Warning, "ComponentCreator: Cannot create a component of "
                                             "type " + type);
        return (nullptr);
    }
    return (IComponent *) ((*this).*creationTab.at(type))(value);
}

/*
nts::IComponent *nts::ComponentCreator::createComponent(const std::string &type,
                                                        const std::string &value)
{
    switch (std::stoi(type))
    {
*/
/*
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
*//*

        default:
            return nullptr;
    }
}
*/

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
