//
// Created by Pierre Bougon on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENTCREATOR_H_
#define NANOTEKSPICE_COMPONENTCREATOR_H_

#include <string>
#include <map>
#include <functional>
#include "IComponent.h"

namespace nts
{
    class ComponentCreator
    {
    private:
        // Map to store the creator functions
        typedef IComponent *(ComponentCreator::*createFunc)(const std::string
                                                                   &value) const;
        std::map<std::string, createFunc> creationTab;

    public:
        ComponentCreator();


        IComponent *createComponent(const std::string &type,
                                    const std::string &value) const;

    private:
        IComponent *create2716(const std::string &value) const;
        IComponent *create4001(const std::string &value) const;
        IComponent *create4008(const std::string &value) const;
        IComponent *create4011(const std::string &value) const;
        IComponent *create4013(const std::string &value) const;
        IComponent *create4017(const std::string &value) const;
        IComponent *create4030(const std::string &value) const;
        IComponent *create4040(const std::string &value) const;
        IComponent *create4069(const std::string &value) const;
        IComponent *create4071(const std::string &value) const;
        IComponent *create4081(const std::string &value) const;
        IComponent *create4094(const std::string &value) const;
        IComponent *create4503(const std::string &value) const;
        IComponent *create4512(const std::string &value) const;
        IComponent *create4514(const std::string &value) const;
        IComponent *createi4004(const std::string &value) const;
        IComponent *createmk4801(const std::string &value) const;
        IComponent *createInput(const std::string &value) const;
        IComponent *createOutput(const std::string &value) const;
    };
}


#endif // !NANOTEKSPICE_COMPONENTCREATOR_H_
