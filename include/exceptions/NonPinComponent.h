//
// Created by peau_c on 3/3/17.
//

#ifndef NANOTEKSPICE_NONPINCOMPONENT_H
#define NANOTEKSPICE_NONPINCOMPONENT_H

namespace nts {
	namespace Exception {
		class NonPinComponent : public std::exception {
		public:
			NonPinComponent() throw();
			virtual char const *what() const throw();
		};
	}
}

#endif //NANOTEKSPICE_NONPINCOMPONENT_H
