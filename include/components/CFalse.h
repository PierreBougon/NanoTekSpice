//
// Created by Pierre Bougon on 14/02/17.
//

#ifndef NANOTEKSPICE_CFALSE_H_
#define NANOTEKSPICE_CFALSE_H_


#include "CInput.h"

namespace nts
{
    namespace Component
    {
        class CFalse : public CInput
        {
        public:
            CFalse(const std::string &name);

            virtual ~CFalse();
        };
    }
}


#endif // !NANOTEKSPICE_CFALSE_H_
