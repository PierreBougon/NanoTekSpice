//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4013_H_
#define NANOTEKSPICE_C4013_H_

#include "components/pins/ClockedPin.h"
#include "components/pins/BasicOutputPin.h"
#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4013 : public AComponent
        {
        public:
            C4013(const std::string &name);

            Tristate Compute(size_t pin_num_this) override;

            virtual ~C4013();

        private:
            BasicPin * getData(int num = 1);
            BasicPin *getReset(int num = 1);
            BasicPin *getSet(int num = 1);
            ClockedPin *getClock(int num = 1);
            BasicOutputPin *getQ(int num = 1);
            BasicOutputPin *getQbar(int num = 1);

            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;

            Tristate returnValueOfCompute(size_t aThis);
        };
    }
}

#endif // !NANOTEKSPICE_C4013_H_
