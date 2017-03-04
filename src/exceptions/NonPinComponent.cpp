//
// Created by peau_c on 3/3/17.
//


#include "exceptions/NonPinComponent.h"

nts::Exception::NonPinComponent::NonPinComponent() throw() : std::exception() {

}

char const *nts::Exception::NonPinComponent::what() const throw() {
	return ("Tried to use getType() on a nonPinComponent");
}

