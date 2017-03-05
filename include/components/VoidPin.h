//
// Created by peau_c on 3/5/17.
//

#ifndef NANOTEKSPICE_VOIDPIN_H
#define NANOTEKSPICE_VOIDPIN_H

#include "components/APin.h"
#include "components/IComponent.h"
#include "components/InputPin.h"

namespace nts {
	namespace Component {
		class VoidPin : public APin {
		public:
			VoidPin();

			virtual ~VoidPin();
			Tristate compute(IComponent const &component) override;
			bool link(APin const *toLink) override;
			Tristate getState() const override;
		};
	}
}
#endif //NANOTEKSPICE_VOIDPIN_H
