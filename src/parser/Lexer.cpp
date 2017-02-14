//
// Created by peau_c on 2/8/17.
//

#include <string>
#include "parser/Lexer.h"

void nts::Lexer::getFileNameAndOpenFile(char **av, nts::Utils::FileHandler &file) {
	std::string tmp;
	for (int i = 0; av[i]; i++) {
		tmp = av[i];
		if (tmp.find(".nts") != tmp.npos) {
			file.setFileName(tmp);
			break;
		}
	}
}

void nts::Lexer::readFileAndBuildTree(nts::Utils::FileHandler &fileHandler, nts::Parser &parser) {
	for(std::string line = fileHandler.getValidLine(); line != ""; line = fileHandler.getValidLine()) {
		parser.feed(line);
	}

}

void nts::Lexer::readFileAndArguments(char **av, nts::Parser &parser) {
	nts::Utils::FileHandler file;

	nts::Lexer::getFileNameAndOpenFile(av, file);
	nts::Lexer::readFileAndBuildTree(file, parser);
}
