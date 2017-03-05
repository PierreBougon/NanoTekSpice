//
// Created by Pierre Bougon on 13/02/17.
//

#ifndef NANOTEKSPICE_INPUTCOMPONENT_H_
#define NANOTEKSPICE_INPUTCOMPONENT_H_


#include <string>
#include "components/pins/IComponent.h"
#include "components/pins/SimpleInputPin.h"
#include "AComponent.h"

namespace nts
{
    namespace Component
    {
        class CInput : public AComponent
        {
        public:
            CInput(const std::string &name);

            virtual ~CInput();

            void            setState(Tristate state);

            Tristate        getState() const;

        protected:
            Tristate gate(nts::Component::InputPin const *inputPin1,
                          nts::Component::InputPin const *inputPin2) const override;
        };
    }
}


#endif // !NANOTEKSPICE_INPUTCOMPONENT_H_
