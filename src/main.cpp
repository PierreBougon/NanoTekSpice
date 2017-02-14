//
// Created by Pierre Bougon on 01/02/17.
//
#include <iostream>
#include <utils/Logger.h>
#include <signal.h>
#include <SignalHandler.h>
#include "utils/FileHandler.h"
#include "parser/Parser.h"
#include "parser/Lexer.h"

void getStandardInput(nts::Parser parser);
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
void getStandardInput(nts::Parser parser) {
    std::string inputLine;

    while (std::cin) {
        getline(std::cin, inputLine);
        std::cout << inputLine << std::endl;
    }

}
