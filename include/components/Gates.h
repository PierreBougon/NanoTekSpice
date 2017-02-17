//
// Created by Pierre Bougon on 16/02/17.
//

#ifndef NANOTEKSPICE_GATES_H_
#define NANOTEKSPICE_GATES_H_

#include "IComponent.h"

namespace nts
{
    namespace Gate
    {
        Tristate xorGate(Tristate a, Tristate b);

        Tristate norGate(Tristate a, Tristate b);

        Tristate andGate(Tristate a, Tristate b);

        Tristate orGate(Tristate a, Tristate b);


    }
}

#endif // !NANOTEKSPICE_GATES_H_
