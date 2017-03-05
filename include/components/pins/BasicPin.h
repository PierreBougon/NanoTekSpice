//
// Created by Pierre Bougon on 01/03/17.
//

#ifndef NANOTEKSPICE_BASICPIN_H_
#define NANOTEKSPICE_BASICPIN_H_


#include "APin.h"

namespace nts
{
    namespace Component
    {
        class BasicPin : public APin
        {
        private:
            APin const *linked;

        public:
            BasicPin();

            virtual Tristate compute(IComponent const &component) override;

            virtual bool link(APin const *toLink) override;

            virtual Tristate getState() const override;
        };
    }
}


#endif // !NANOTEKSPICE_BASICPIN_H_
