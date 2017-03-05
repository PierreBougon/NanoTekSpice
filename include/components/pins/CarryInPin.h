//
// Created by Pierre Bougon on 05/03/17.
//

#ifndef NANOTEKSPICE_CARRYINPIN_H_
#define NANOTEKSPICE_CARRYINPIN_H_


#include "InputPin.h"

namespace nts
{
    namespace Component
    {
        class CarryInPin : public InputPin
        {
        private:
            Tristate state;

        public:
            CarryInPin();

            virtual ~CarryInPin();

            void setState(Tristate _state);

            Tristate getState() const override;
        };
    }
}


#endif // !NANOTEKSPICE_CARRYINPIN_H_
