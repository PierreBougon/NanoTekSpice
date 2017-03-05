//
// Created by peau_c on 3/5/17.
//

#include "components/pins/VoidPin.h"

nts::Component::VoidPin::VoidPin() : APin(nts::Component::PinType::UNDEFINED) {}

nts::Component::VoidPin::~VoidPin() {}

nts::Tristate nts::Component::VoidPin::compute(const nts::IComponent &component) {
	return nts::Tristate::UNDEFINED;
}

bool nts::Component::VoidPin::link(const nts::Component::APin *toLink) {
	return false;
}

nts::Tristate nts::Component::VoidPin::getState() const {
	return nts::Tristate::UNDEFINED;
}
