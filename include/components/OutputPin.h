//
// Created by Pierre Bougon on 07/02/17.
//

#ifndef NANOTEKSPICE_OUTPUTPIN_H_
#define NANOTEKSPICE_OUTPUTPIN_H_

#include <vector>
#include "APin.h"
#include "InputPin.h"

namespace nts
{
    namespace Component
    {
        class OutputPin : public APin
        {
        private:
            InputPin const *inputPin1;
            InputPin const *inputPin2;
        protected:
            Tristate computedState;

         public:
            OutputPin(const InputPin *inputPin1, const InputPin *inputPin2);

            virtual ~OutputPin();

            Tristate compute(IComponent const &component) override;

            bool link(APin const *pin) override;

            const InputPin *getInputPin1() const;

            void setInputPin1(const InputPin *inputPin1);

            const InputPin *getInputPin2() const;

            void setInputPin2(const InputPin *inputPin2);

            Tristate getState() const;

            void resetCompute();
        };
    }
}


#endif // !NANOTEKSPICE_OUTPUTPIN_H_
