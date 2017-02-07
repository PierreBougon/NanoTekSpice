//
// Created by Pierre Bougon on 07/02/17.
//

#ifndef NANOTEKSPICE_SIMPLEINPUTPIN_H_
#define NANOTEKSPICE_SIMPLEINPUTPIN_H_


#include "APin.h"

namespace nts
{
    namespace Component
    {
        class SimpleInputPin : public APin
        {
        private:
            nts::Tristate sate;
        };
    }
}


#endif // !NANOTEKSPICE_SIMPLEINPUTPIN_H_
