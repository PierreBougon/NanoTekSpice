//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4503_H_
#define NANOTEKSPICE_C4503_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4503 : public AComponent
        {
        public:
            C4503(const std::string &name);
        };
    }
}

#endif // !NANOTEKSPICE_C4503_H_