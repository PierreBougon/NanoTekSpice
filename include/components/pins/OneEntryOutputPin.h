//
// Created by Pierre Bougon on 27/02/17.
//

#ifndef NANOTEKSPICE_ONEENTRYOUTPUTPIN_H_
#define NANOTEKSPICE_ONEENTRYOUTPUTPIN_H_

#include "OutputPin.h"


namespace nts
{
    namespace Component
    {
        class OneEntryOutputPin : public OutputPin
        {
        public:
            OneEntryOutputPin(const InputPin *inputPin);

            virtual ~OneEntryOutputPin() override;

            Tristate compute(IComponent const &component) override;

            bool link(APin const *pin) override;

            const InputPin *getInputPin() const;

            void setInputPin(const InputPin *inputPin);

        private:


            const InputPin *getInputPin2() const override;

            void setInputPin2(const InputPin *inputPin2) override;

            const InputPin *getInputPin1() const override;

            void setInputPin1(const InputPin *inputPin1) override;
        };
    }
}


#endif // !NANOTEKSPICE_ONEENTRYOUTPUTPIN_H_
