//
// Created by peau_c on 3/5/17.
//

#ifndef NANOTEKSPICE_NONIMPLEMENTED_H
#define NANOTEKSPICE_NONIMPLEMENTED_H

#include <string>
#include "exception"

namespace nts {
	namespace Exception {
		class NonImplemented : public std::exception {
		public:
			NonImplemented(std::string const &name) throw();
			virtual char const *what() const throw();
		private:
			std::string _name;
		};
	}
}

#endif //NANOTEKSPICE_NONIMPLEMENTED_H
