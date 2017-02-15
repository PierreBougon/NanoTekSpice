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

void createFunctionMap(std::map<std::string, std::function<void()>> map) {
	std::function<void()>	functorPtr = exit;

	functorPtr = exit;
	map["exit"] = functorPtr;
	functorPtr = display;
	map["display"] = functorPtr;
	functorPtr = dump;
	map["dump"] = functorPtr;
	functorPtr = loop;
	map["loop"] = functorPtr;
	functorPtr = input;
	map["input"] = functorPtr;
	functorPtr = simulate;
	map["simulate"] = functorPtr;

}

void getStandardInput(nts::Parser parser) {
	std::string 										inputLine;
	std::map<std::string, std::function<void()>>	functionMap;

	createFunctionMap(functionMap);
	while (std::cin) {
		getline(std::cin, inputLine);


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

