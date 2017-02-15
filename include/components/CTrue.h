//
// Created by Pierre Bougon on 14/02/17.
//

#ifndef NANOTEKSPICE_CTRUE_H_
#define NANOTEKSPICE_CTRUE_H_


#include "CInput.h"

namespace nts
{
    namespace Component
    {
        class CTrue : public CInput
        {
        public:
            CTrue(const std::string &name);

            ~CTrue() override;
        };
    }
}


#endif // !NANOTEKSPICE_CTRUE_H_
