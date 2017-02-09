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
            std::vector<APin>   pinList;
            int                 nbPin;


        public:
            AComponent() = delete;
            AComponent(const std::string &name);
            virtual ~AComponent();

        public:
            Tristate Compute(size_t pin_num_this) override;

            void SetLink(size_t pin_num_this, nts::IComponent &component,
                         size_t pin_num_target) override;

            void Dump(void) const override;

            const std::string &getName() const;

            void setName(const std::string &name);

            APin const *getPinAt(size_t pin_num_this) const;

        private:
            APin *_getPinAt(size_t pin_num_this);
        };
    }
}

#endif // !NANOTEKSPICE_ACOMPONENT_H_
