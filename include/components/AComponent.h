//
// Created by Pierre Bougon on 06/02/17.
//

#ifndef NANOTEKSPICE_ACOMPONENT_H_
#define NANOTEKSPICE_ACOMPONENT_H_

#include <string>
#include "IComponent.h"

namespace nts
{
    namespace Component
    {
        class AComponent : public IComponent
        {
        protected:
            std::string name;
        public:
            AComponent();
            AComponent(const std::string &name);
            virtual ~AComponent();

        private:
        public:
            const std::string &getName() const;

            void setName(const std::string &name);
        };
    }
}

#endif // !NANOTEKSPICE_ACOMPONENT_H_
