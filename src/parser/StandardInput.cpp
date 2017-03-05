//
// Created by peau_c on 3/2/17.
//

#include <iostream>
#include <utils/Logger.h>
#include "parser/StandardInput.h"
#include "components/COutput.h"
#include "components/CInput.h"

void StandardInput::createFunctionMap(std::map<std::string, void (*)(nts::Parser &)> &map) {
	map["exit"] = &nts::Commands::exitFunc;
	map["display"] = &nts::Commands::display;
	map["dump"] = &nts::Commands::dump;
	map["loop"] = &nts::Commands::loop;
	map["simulate"] = &nts::Commands::simulate;
}

void StandardInput::setInput(std::string string, nts::Parser &parser, unsigned long equalPos) {
	std::string componentName, value;
	nts::Component::CInput *CInput;
	long tmp = 0;

	componentName = string.substr(0, equalPos);
	CInput = static_cast<nts::Component::CInput *>(parser.getItemFromList(componentName));
	if (!CInput) {
		Logger::log(Logger::Warning, "Input name not found, please check the syntax", false);
		return;
	}
	if ((value = string.substr(equalPos + 1)).empty()) {
		Logger::log(Logger::Warning, "Please set a correct value for input", false);
		return;
	}
	if (value[0] == ' ') {
		Logger::log(Logger::Warning, "No spaces allowed after '='", false);
		return ;
	}
	else
		tmp = std::stol(value);
	CInput->setState((tmp > 0 ? nts::Tristate::TRUE : nts::Tristate::FALSE));
}

void StandardInput::executeCommand(std::string input, std::map<std::string, void (*)(nts::Parser &)> &map, nts::Parser &parser) {
	if (input.find("=") != input.npos) {
		setInput(input, parser, input.find("="));
	} else {
		try {
			map.at(input)(parser);
		}
		catch (std::out_of_range e) {
			Logger::log(Logger::Warning, "Command \"" + input + "\" is not recognized, check for typos", false);
		}
	}
}

void StandardInput::getStandardInput(nts::Parser &parser) {
	std::string inputLine;
	std::map<std::string, void (*)(nts::Parser &)> map;

	createFunctionMap(map);
	while (std::cin) {
		std::cout << "> ";
		getline(std::cin, inputLine);
		if (inputLine.empty())
			continue;
		executeCommand(inputLine, map, parser);
	}
}
