//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4081_H_
#define NANOTEKSPICE_C4081_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4081 : public AComponent
        {
        public:
            C4081(const std::string &name);

        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_C4081_H_
