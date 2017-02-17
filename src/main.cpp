//
// Created by Pierre Bougon on 01/02/17.
//
#include <map>
#include <iostream>
#include <signal.h>
#include "utils/SignalHandler.h"
#include "components/COutput.h"
#include "utils/Logger.h"
#include "components/CInput.h"
#include "utils/FileHandler.h"
#include "parser/Parser.h"
#include "parser/Lexer.h"

void exit(nts::Parser &parser) {
	exit(0);
}

void display(nts::Parser &parser) {
	for(std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin();
		it < parser.getComponentList().end(); ++it) {
		if (dynamic_cast<nts::Component::COutput *> (*it) != nullptr) {
			std::cout << (*it)->getName() << "=" << (*it)->getStateAt() << std::endl;
		}
	}
}

void simulate(nts::Parser &parser) {
	printf("simulate\n");
}



void loop(nts::Parser &parser) {
	signal(SIGINT, SignalHandler::sigHandlerInt);
	while (!g_interuptLoop) {
	 	simulate(parser);
	}
	g_interuptLoop = 0;
}

void dump(nts::Parser &parser) {
	for(std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin();
		it < parser.getComponentList().end(); ++it)
		(*it)->Dump();
}

void createFunctionMap(std::map<std::string, void (*)(nts::Parser &)> &map) {
	map["exit"] = &exit;
	map["display"] = &display;
	map["dump"] = &dump;
	map["loop"] = &loop;
	map["simulate"] = &simulate;
}

void setInput(std::string string, nts::Parser parser, unsigned long equalPos) {
	std::string componentName, value;
	nts::Component::CInput *getter;
	long tmp = 0;

	componentName = string.substr(0, equalPos);
	getter = static_cast<nts::Component::CInput *>(parser.getItemFromList(componentName));
	if (!getter) {
		Logger::log(Logger::Warning, "Input name not found, please check the syntax", false);
		return;
	}
	if ((value = string.substr(equalPos + 1)).empty()) {
		Logger::log(Logger::Warning, "Please set a correct value for input", false);
		return;
	}
	tmp = std::stol(value);
	getter->setState((tmp > 0 ? nts::Tristate::TRUE : nts::Tristate::FALSE));
}

void executeCommand(std::string input, std::map<std::string, void (*)(nts::Parser &)> map, nts::Parser parser) {
	if (input.find("=") != input.npos) {
		setInput(input, parser, input.find("="));
	} else {
		try {
			map.at(input)(parser);
		}
		catch (std::out_of_range e) {
			Logger::log(Logger::Warning, "Command \"" + input + "\" is not regocnized, check for typos", false);
		}
	}
}

void getStandardInput(nts::Parser &parser) {
	std::string inputLine;
	std::map<std::string, void (*)(nts::Parser &)> functionMap;

	createFunctionMap(functionMap);
	while (std::cin) {
		std::cout << "> ";
		getline(std::cin, inputLine);

		if (inputLine.empty())
			continue;
		executeCommand(inputLine, functionMap, parser);
	}

}

int main(int ac, char **av) {
	nts::Parser parser;
	Debug::DEBUG_MODE = true;
	signal(SIGINT, &SignalHandler::sigHandlerInt);
	if (ac < 2)
		Logger::log(Logger::Error, "Usage: ./nanotekspice file [Options]", true);
	nts::Lexer::readFileAndArguments(av, parser);
	parser.checkChipset();
	parser.checkLinks();
	parser.parseTree(*(parser.getRoot()));
	getStandardInput(parser);
	return (0);
}

