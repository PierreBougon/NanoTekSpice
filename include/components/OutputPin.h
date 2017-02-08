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
            InputPin inputPin1;
            InputPin inputPin2;
//            std::vector<APin const &> linkedPin;
        public:
//            Tristate compute() override;
        };
    }
}


#endif // !NANOTEKSPICE_OUTPUTPIN_H_
