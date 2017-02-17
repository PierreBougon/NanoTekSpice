//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_ACOMPONENT_H_
#define NANOTEKSPICE_ACOMPONENT_H_

#include <string>
#include <vector>
#include "IComponent.h"
#include "APin.h"

namespace nts
{
    namespace Component
    {
        class AComponent : public IComponent
        {
        protected:
            /*________________________
             * ## Class attributes ##
             * ----------------------*/
            std::string         name;
            std::vector<APin *> pinList;
            int                 nbPin;


        public:
            AComponent() = delete;
            AComponent(const std::string &name);
            virtual ~AComponent();

        public:
            virtual Tristate Compute(size_t pin_num_this) override;

            virtual void SetLink(size_t pin_num_this, nts::IComponent &component,
                         size_t pin_num_target) override;

            virtual void Dump(void) const override;

            virtual const std::string &getName() const;

            virtual void setName(const std::string &name);

            virtual APin const *getPinAt(size_t pin_num_this) const;

            void onSimulationFinished() override;

            Tristate getStateAt(size_t pin_num_this = 0);

        private:
            virtual APin *_getPinAt(size_t pin_num_this);
        };
    }
}

#endif // !NANOTEKSPICE_ACOMPONENT_H_
