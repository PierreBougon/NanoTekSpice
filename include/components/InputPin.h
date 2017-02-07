//
// Created by Pierre Bougon on 07/02/17.
//

#ifndef NANOTEKSPICE_PIN_H_
#define NANOTEKSPICE_PIN_H_

#include "APin.h"
#include "SimpleInputPin.h"

namespace nts
{
    namespace Component
    {
        class InputPin : public APin
        {
        private:
            const SimpleInputPin *inputPin;

        public:
            InputPin(SimpleInputPin *inputPin = nullptr);

            virtual ~InputPin();

            nts::Tristate getState() const;
        };
    }
}


#endif // !NANOTEKSPICE_PIN_H_
