//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4040_H_
#define NANOTEKSPICE_C4040_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4040 : public AComponent
        {
        public:
            C4040(const std::string &name);
        };
    }
}

#endif // !NANOTEKSPICE_C4040_H_