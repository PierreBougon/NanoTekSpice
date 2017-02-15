//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4512_H_
#define NANOTEKSPICE_C4512_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4512 : public AComponent
        {
        public:
            C4512(const std::string &name);

            virtual ~C4512();

        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_C4512_H_
