//
// Created by peau_c on 3/2/17.
//

#ifndef NANOTEKSPICE_STANDARDINPUT_H
#define NANOTEKSPICE_STANDARDINPUT_H

#include <string>
#include "parser/Parser.h"
#include "parser/Commands.h"

class StandardInput {
//METHODS
public:
	static void getStandardInput(nts::Parser &parser);
private:
	static void createFunctionMap(std::map<std::string, void (*)(nts::Parser &)> &map);
	static void executeCommand(std::string input, std::map<std::string, void (*)(nts::Parser &)> &map, nts::Parser &parser);
	static void setInput(std::string string, nts::Parser &parser, unsigned long equalPos);
};

#endif //NANOTEKSPICE_STANDARDINPUT_H
