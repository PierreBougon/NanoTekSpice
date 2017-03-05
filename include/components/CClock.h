//
// Created by Pierre Bougon on 15/02/17.
//

#ifndef NANOTEKSPICE_CCLOCK_H_
#define NANOTEKSPICE_CCLOCK_H_


#include "CInput.h"

namespace nts
{
    namespace Component
    {
        class CClock : public CInput
        {
        public:
            CClock(const std::string &name);

            virtual void onSimulationFinished() override;
        };
    }
}


#endif // !NANOTEKSPICE_CCLOCK_H_
