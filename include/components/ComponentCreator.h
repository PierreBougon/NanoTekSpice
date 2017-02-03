//
// Created by Pierre Bougon on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENTCREATOR_H_
#define NANOTEKSPICE_COMPONENTCREATOR_H_

#include <string>
#include "IComponent.h"

namespace nts
{
    class ComponentCreator
    {
    public:
        static IComponent *createComponent(const std::string &type,
                                           const std::string &value);

    private:
        static IComponent *create2716(const std::string &value) const;
        static IComponent *create4001(const std::string &value) const;
        static IComponent *create4008(const std::string &value) const;
        static IComponent *create4011(const std::string &value) const;
        static IComponent *create4013(const std::string &value) const;
        static IComponent *create4017(const std::string &value) const;
        static IComponent *create4030(const std::string &value) const;
        static IComponent *create4040(const std::string &value) const;
        static IComponent *create4069(const std::string &value) const;
        static IComponent *create4071(const std::string &value) const;
        static IComponent *create4081(const std::string &value) const;
        static IComponent *create4094(const std::string &value) const;
        static IComponent *create4503(const std::string &value) const;
        static IComponent *create4512(const std::string &value) const;
        static IComponent *create4514(const std::string &value) const;
        static IComponent *createi4004(const std::string &value) const;
        static IComponent *createmk4801(const std::string &value) const;
    };
}


#endif // !NANOTEKSPICE_COMPONENTCREATOR_H_
