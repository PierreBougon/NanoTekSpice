//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_CI4004_H_
#define NANOTEKSPICE_CI4004_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class Ci4004 : public AComponent
        {
        public:
            Ci4004(const std::string &name);

            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_CI4004_H_
