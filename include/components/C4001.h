//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4001_H_
#define NANOTEKSPICE_C4001_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4001 : public AComponent
        {
        public:
            C4001(const std::string &name);
        };
    }
}

#endif // !NANOTEKSPICE_C4001_H_
