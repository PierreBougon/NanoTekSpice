//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4030_H_
#define NANOTEKSPICE_C4030_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4030 : public AComponent
        {
        public:
            C4030(const std::string &name);
        };
    }
}

#endif // !NANOTEKSPICE_C4030_H_
