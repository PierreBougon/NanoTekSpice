//
// Created by peau_c on 3/3/17.
//

#include "exceptions/NonImplemented.h"

nts::Exception::NonImplemented::NonImplemented(std::string const &name) throw() : std::exception() {
	_name = name;
}

char const *nts::Exception::NonImplemented::what() const throw() {
	std::string error = "Chipset " + _name + " is not yet implemented\n";
	return (error.c_str());
}

