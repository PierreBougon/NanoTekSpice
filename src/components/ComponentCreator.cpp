//
// Created by Pierre Bougon on 03/02/17.
//

#include "components/COutput.h"
#include "components/CInput.h"
#include "components/CClock.h"
#include "components/C2716.h"
#include "utils/Logger.h"
#include "components/Ci4004.h"
#include "components/C4514.h"
#include "components/C4512.h"
#include "components/C4503.h"
#include "components/Cmk4801.h"
#include "components/C4094.h"
#include "components/C4081.h"
#include "components/C4071.h"
#include "components/C4069.h"
#include "components/C4040.h"
#include "components/C4030.h"
#include "components/C4017.h"
#include "components/C4013.h"
#include "components/C4011.h"
#include "components/ComponentCreator.h"
#include "components/C4001.h"
#include "components/C4008.h"

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
    creationTab["input"] = &ComponentCreator::createInput;
    creationTab["output"] = &ComponentCreator::createOutput;
    creationTab["clock"] = &ComponentCreator::createClock;
}

nts::IComponent *nts::ComponentCreator::createComponent(const std::string &type,
                                                        const std::string &value) const
{
    if (creationTab.find(type) == creationTab.end())
    {
        Logger::log(Logger::Warning, "ComponentCreator: Cannot create a component of "
                                             "type " + type);
        throw new std::invalid_argument(type);
    }
    return (IComponent *) ((*this).*creationTab.at(type))(value);
}

nts::IComponent *nts::ComponentCreator::create2716(const std::string &value) const
{
    return new nts::Component::C2716(value);
}

nts::IComponent *nts::ComponentCreator::create4001(const std::string &value) const
{
    return new nts::Component::C4001(value);
}

nts::IComponent *nts::ComponentCreator::create4008(const std::string &value) const
{
    return new nts::Component::C4008(value);
}

nts::IComponent *nts::ComponentCreator::create4011(const std::string &value) const
{
    return new nts::Component::C4011(value);
}

nts::IComponent *nts::ComponentCreator::create4013(const std::string &value) const
{
    return new nts::Component::C4013(value);
}

nts::IComponent *nts::ComponentCreator::create4017(const std::string &value) const
{
    return new nts::Component::C4017(value);
}

nts::IComponent *nts::ComponentCreator::create4030(const std::string &value) const
{
    return new nts::Component::C4030(value);
}

nts::IComponent *nts::ComponentCreator::create4040(const std::string &value) const
{
    return new nts::Component::C4040(value);
}

nts::IComponent *nts::ComponentCreator::create4069(const std::string &value) const
{
    return new nts::Component::C4069(value);
}

nts::IComponent *nts::ComponentCreator::create4071(const std::string &value) const
{
    return new nts::Component::C4071(value);
}

nts::IComponent *nts::ComponentCreator::create4081(const std::string &value) const
{
    return new nts::Component::C4081(value);
}

nts::IComponent *nts::ComponentCreator::create4094(const std::string &value) const
{
    return new nts::Component::C4094(value);
}

nts::IComponent *nts::ComponentCreator::create4503(const std::string &value) const
{
    return new nts::Component::C4503(value);
}

nts::IComponent *nts::ComponentCreator::create4512(const std::string &value) const
{
    return new nts::Component::C4512(value);
}

nts::IComponent *nts::ComponentCreator::create4514(const std::string &value) const
{
    return new nts::Component::C4514(value);
}

nts::IComponent *nts::ComponentCreator::createi4004(const std::string &value) const
{
    return new nts::Component::Ci4004(value);
}

nts::IComponent *nts::ComponentCreator::createmk4801(const std::string &value) const
{
    return new nts::Component::Cmk4801(value);
}

nts::IComponent *nts::ComponentCreator::createOutput(const std::string &value) const
{
    return new nts::Component::COutput(value);
}

nts::IComponent *nts::ComponentCreator::createInput(const std::string &value) const
{
    return new nts::Component::CInput(value);
}

nts::IComponent *nts::ComponentCreator::createClock(const std::string &value) const
{
    return new nts::Component::CClock(value);
}
