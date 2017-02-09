//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4011_H_
#define NANOTEKSPICE_C4011_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4011 : public AComponent
        {
        public:
            C4011(const std::string &name);

            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_C4011_H_
