//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4071_H_
#define NANOTEKSPICE_C4071_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4071 : public AComponent
        {
        public:
            C4071(const std::string &name);

            virtual ~C4071();

        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}

#endif // !NANOTEKSPICE_C4071_H_
