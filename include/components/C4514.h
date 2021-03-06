//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4514_H_
#define NANOTEKSPICE_C4514_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4514 : public AComponent
        {
        public:
            C4514(const std::string &name);

            virtual ~C4514();

        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_C4514_H_
