//
// Created by Pierre Bougon on 01/03/17.
//

#ifndef NANOTEKSPICE_CLOCKEDPIN_H_
#define NANOTEKSPICE_CLOCKEDPIN_H_

#include "BasicPin.h"

namespace nts
{
    namespace Component
    {
        enum class ClockState
        {
            Up = 0,
            Down,
            Unknown
        };

        class ClockedPin : public BasicPin
        {
        private:
            mutable ClockState clockState;
        public:
            ClockedPin();

            Tristate compute(IComponent const &component) override;

            Tristate getState() const override;

            void updateClockState(Tristate state) const;

            ClockState getClockState() const;
        };
    }
}


#endif // !NANOTEKSPICE_CLOCKEDPIN_H_
