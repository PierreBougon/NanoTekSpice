//
// Created by Pierre Bougon on 09/02/17.
//

#ifndef NANOTEKSPICE_SIMPLEOUTPUTPIN_H_
#define NANOTEKSPICE_SIMPLEOUTPUTPIN_H_


#include <vector>
#include "APin.h"
#include "OutputPin.h"

namespace nts
{
    namespace Component
    {
        class SimpleOutputPin : public APin
        {
        private:
            std::vector<OutputPin const *> listOutputPin;

            size_t pinIt;

            Tristate state;
        public:
            SimpleOutputPin();

            virtual ~SimpleOutputPin();

            Tristate compute(IComponent const &component) override;

            Tristate compute(IComponent const &component, size_t it);

            bool link(APin const *toLink) override;

            Tristate getState() const override;

            void reset();
        };
    }
}


#endif // !NANOTEKSPICE_SIMPLEOUTPUTPIN_H_
