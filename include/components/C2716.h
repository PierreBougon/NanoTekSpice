//
// Created by Pierre Bougon on 09/02/17.
//

#ifndef NANOTEKSPICE_C2716_H_
#define NANOTEKSPICE_C2716_H_


#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C2716 : public AComponent
        {
        public:
            C2716(const std::string &name);
        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}


#endif // !NANOTEKSPICE_C2716_H_
