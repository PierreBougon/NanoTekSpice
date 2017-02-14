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
            SimpleInputPin const *inputPin;

        public:
            InputPin(SimpleInputPin const *inputPin = nullptr);

            virtual ~InputPin();

            Tristate compute(IComponent const &component) override;

            bool link(APin const *pin) override;

            nts::Tristate getState() const override;

            const SimpleInputPin *getInputPin() const;

            void setInputPin(const SimpleInputPin *inputPin);
        };
    }
}


#endif // !NANOTEKSPICE_PIN_H_
