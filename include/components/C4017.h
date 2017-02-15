//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4017_H_
#define NANOTEKSPICE_C4017_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4017 : public AComponent
        {
        public:
            C4017(const std::string &name);

            virtual ~C4017();

        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_C4017_H_
