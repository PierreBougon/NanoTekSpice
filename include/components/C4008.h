//
// Created by Pierre Bougon on 09/02/17.
//

#ifndef NANOTEKSPICE_C4008_H_
#define NANOTEKSPICE_C4008_H_

#include "components/AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4008 : public AComponent
        {
        public:
            C4008(const std::string &name);

            virtual ~C4008();

            Tristate    getCarryOutState() const;
            const APin  *getCarryOut() const;
            APin        *_getCarryOut();
        protected:
            Tristate    getCarryInState() const;
            const CarryInPin        *getCarryIn() const;

        private:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}


#endif // !NANOTEKSPICE_C4008_H_
