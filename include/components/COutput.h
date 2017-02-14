//
// Created by Pierre Bougon on 13/02/17.
//

#ifndef NANOTEKSPICE_OUTPUTCOMPONENT_H_
#define NANOTEKSPICE_OUTPUTCOMPONENT_H_


#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class COutput : public AComponent
        {
        public:
            COutput(const std::string &name);

        protected:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}


#endif // !NANOTEKSPICE_OUTPUTCOMPONENT_H_
