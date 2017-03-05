//
// Created by Pierre Bougon on 17/02/17.
//

#ifndef NANOTEKSPICE_CARRYINPIN_H_
#define NANOTEKSPICE_CARRYINPIN_H_


#include "components/pins/OutputPin.h"
#include "components/pins/VoidPin.h"

namespace nts
{
    namespace Component
    {
        class CarryOutPin : public OutputPin
        {
        public:
            CarryOutPin(const InputPin *inputPin1 = (InputPin *)new const VoidPin(), const InputPin *inputPin2
            = (InputPin *)new const VoidPin());

            virtual ~CarryOutPin();

            void setState(Tristate state);

            bool isCorrectlyLinked() override;
        };
    }
}


#endif // !NANOTEKSPICE_CARRYINPIN_H_
