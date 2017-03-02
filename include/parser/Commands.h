//
// Created by peau_c on 3/2/17.
//

#ifndef NANOTEKSPICE_COMMANDS_H
#define NANOTEKSPICE_COMMANDS_H

#include "parser/Parser.h"

namespace nts {
	namespace Commands {
		//Every function must be of type void (*)(nts::Parser &parser)
		void display(nts::Parser &parser);
		void simulate(nts::Parser &parser);
		void exitFunc(nts::Parser &parser);
		void loop(nts::Parser &parser);
		void dump(nts::Parser &parser);
	};
};

#endif //NANOTEKSPICE_COMMANDS_H
