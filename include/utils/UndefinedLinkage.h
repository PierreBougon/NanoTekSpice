//
// Created by peau_c on 3/1/17.
//

#ifndef NANOTEKSPICE_UNDEFINEDLINKAGE_H
#define NANOTEKSPICE_UNDEFINEDLINKAGE_H

#include <exception>

namespace nts {
	namespace Exception {
		class UndefinedLinkage : public std::exception {
		public:
			UndefinedLinkage() throw();
			virtual char const *what() const throw();
		};
	}
}
#endif //NANOTEKSPICE_UNDEFINEDLINKAGE_H
