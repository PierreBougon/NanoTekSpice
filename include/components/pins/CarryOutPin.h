//
// Created by Pierre Bougon on 17/02/17.
//

#ifndef NANOTEKSPICE_CARRYINPIN_H_
#define NANOTEKSPICE_CARRYINPIN_H_


#include "components/pins/OutputPin.h"

namespace nts
{
    namespace Component
    {
        class CarryOutPin : public OutputPin
        {
        public:
            CarryOutPin(const InputPin *inputPin1 = nullptr, const InputPin *inputPin2
            = nullptr);

            virtual ~CarryOutPin();

            void setState(Tristate state);
        };
    }
}


#endif // !NANOTEKSPICE_CARRYINPIN_H_
