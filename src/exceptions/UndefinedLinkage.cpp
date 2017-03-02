//
// Created by peau_c on 3/1/17.
//

#include "exceptions/UndefinedLinkage.h"

nts::Exception::UndefinedLinkage::UndefinedLinkage() throw() : std::exception() {

}

char const *nts::Exception::UndefinedLinkage::what() const throw() {
	return ("Program terminated after it tried to link an output without having the two input set");
}
