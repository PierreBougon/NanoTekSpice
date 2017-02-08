//
// Created by peau_c on 2/8/17.
//

#ifndef NANOTEKSPICE_LEXER_H
#define NANOTEKSPICE_LEXER_H

#include "parser/Parser.h"
#include "utils/FileHandler.h"

namespace nts {
	class Lexer {
	public:
		static void readFileAndArguments(char **av, nts::Parser &parser);
		static void readFileAndBuildTree(nts::Utils::FileHandler &fileHandler, nts::Parser &parser);
		static void getFileNameAndOpenFile(char **av, nts::Utils::FileHandler &file);
	};
}

#endif //NANOTEKSPICE_LEXER_H
