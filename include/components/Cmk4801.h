//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_CMK4801_H_
#define NANOTEKSPICE_CMK4801_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class Cmk4801 : public AComponent
        {
        public:
            Cmk4801(const std::string &name);

            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_CMK4801_H_
