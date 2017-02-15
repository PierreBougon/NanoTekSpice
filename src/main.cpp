//
// Created by Pierre Bougon on 01/02/17.
//
#include <map>
#include <iostream>
#include <utils/Logger.h>
#include <signal.h>
#include <SignalHandler.h>
#include "utils/FileHandler.h"
#include "parser/Parser.h"
#include "parser/Lexer.h"

void exit() {

}

void display() {

}

void simulate() {

}

void input() {

}

void loop() {

}

void dump() {

}

void createFunctionMap(std::map<std::string, void (*)()> map) {
	map["exit"] = &exit;
	map["display"] = &display;
	map["dump"] = &dump;
	map["loop"] = &loop;
	map["input"] = &input;
	map["simulate"] = &simulate;
}

void setInput(std::string string, nts::Parser parser, unsigned long equalPos) {

}

void executeCommand(std::string input, std::map<std::string, void (*)()> map, nts::Parser parser) {
	if (input.find("=") != input.npos) {
		setInput(input.substr(input.find("=")), parser, input.find("="));
	}
}

void getStandardInput(nts::Parser parser) {
	std::string 										inputLine;
	std::map<std::string, void (*)()>	functionMap;

	createFunctionMap(functionMap);
	while (std::cin) {
		getline(std::cin, inputLine);
		executeCommand(inputLine, functionMap, parser);
	}

}

//TODO: FAIRE LE MAKEFILE;
int main(int ac, char **av)
{
    nts::Parser parser = nts::Parser();
    Debug::DEBUG_MODE = true;
    signal(SIGINT, &SignalHandler::sigHandlerInt);
    if (ac < 2)
        Logger::log(Logger::Error, "Usage: ./nanotekspice file [Options]");
    nts::Lexer::readFileAndArguments(av, parser);
    getStandardInput(parser);
    parser.checkChipset();
    parser.checkLinks();
	parser.parseTree(*(parser.getRoot()));
    return (0);
}

