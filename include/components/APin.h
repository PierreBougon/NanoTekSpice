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
            input = 0,
            output,
            UNDEFINED
        };

        class APin
        {
        protected:
            PinType type;
            nts::Tristate value;

        public:
            APin(PinType type = PinType::UNDEFINED,
                 nts::Tristate value = nts::Tristate::UNDEFINED);

            virtual ~APin();

            virtual nts::Tristate compute() = 0;

            PinType getType() const;

            Tristate getValue() const;

            void setValue(Tristate value);
        };
    }
}


#endif // !NANOTEKSPICE_APIN_H_
