//
// Created by Pierre Bougon on 07/02/17.
//

#ifndef NANOTEKSPICE_APIN_H_
#define NANOTEKSPICE_APIN_H_

#include "IComponent.h"

namespace nts
{
    namespace Component
    {
        enum class PinType
        {
            basic = -1,
            input = 0,
            output,
            simpleInput,
            simpleOutput,
            UNDEFINED
        };

        class APin
        {
        protected:
            PinType type;

        public:
            APin() = delete;
            APin(PinType type);

            virtual ~APin();

            virtual nts::Tristate compute(IComponent const &component) = 0;

            virtual bool link(APin const *toLink) = 0;

            virtual nts::Tristate getState() const = 0;

            PinType getType() const;
        };
    }
}


#endif // !NANOTEKSPICE_APIN_H_
