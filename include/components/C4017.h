//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_C4017_H_
#define NANOTEKSPICE_C4017_H_

#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class C4017 : public AComponent
        {
        public:
            C4017(const std::string &name);
        };
    }
}

#endif // !NANOTEKSPICE_C4017_H_
