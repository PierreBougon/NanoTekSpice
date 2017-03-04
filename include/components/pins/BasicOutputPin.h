//
// Created by Pierre Bougon on 01/03/17.
//

#ifndef NANOTEKSPICE_BASICOUTPUTPIN_H_
#define NANOTEKSPICE_BASICOUTPUTPIN_H_


#include "BasicPin.h"

namespace nts
{
    namespace Component
    {
        class BasicOutputPin : public BasicPin
        {
            Tristate state;
            Tristate prevState;

        public:
            BasicOutputPin();

            void setState(Tristate _state);

            Tristate getState() const override;

            Tristate getPrevState() const;
        };
    }
}


#endif // !NANOTEKSPICE_BASICOUTPUTPIN_H_
