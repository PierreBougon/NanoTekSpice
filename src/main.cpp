//
// Created by Pierre Bougon on 01/02/17.
//
#include <iostream>
#include <Logger.h>
#include <signal.h>
#include <SignalHandler.h>
#include "utils/FileHandler.h"
#include "parser/Parser.h"
#include "parser/Lexer.h"

//TODO: FAIRE LE MAKEFILE;
int main(int ac, char **av)
{
    nts::Parser parser = nts::Parser();
    Debug::DEBUG_MODE = true;
    signal(SIGINT, &SignalHandler::sigHandlerInt);
    if (ac < 2)
        Logger::log(Logger::Error, "Usage: ./nanotekspice file [Options]");
    nts::Lexer::readFileAndArguments(av, parser);
    parser.checkChipset();
    parser.checkLinks();
    return (0);
}
