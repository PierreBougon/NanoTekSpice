//
// Created by Pierre Bougon on 07/02/17.
//

#ifndef NANOTEKSPICE_SIMPLEINPUTPIN_H_
#define NANOTEKSPICE_SIMPLEINPUTPIN_H_

#include "APin.h"

namespace nts
{
    namespace Component
    {
        class SimpleInputPin : public APin
        {
        private:
            nts::Tristate state;

        public:
            SimpleInputPin(Tristate state = nts::Tristate::UNDEFINED);

            virtual ~SimpleInputPin();

            Tristate compute(IComponent const &component) override;

            bool link(APin const *pin) override;

            Tristate getState() const;

            void setState(Tristate state);
        };
    }
}


#endif // !NANOTEKSPICE_SIMPLEINPUTPIN_H_
