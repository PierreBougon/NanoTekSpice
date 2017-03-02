//
// Created by Pierre Bougon on 01/02/17.
//

#include <signal.h>
#include "utils/SignalHandler.h"
#include "utils/Logger.h"
#include "parser/Lexer.h"
#include "parser/StandardInput.h"

//TODO: LES EXCEPTIONS !!!
int main(int ac, char **av) {
	nts::Parser parser;
	Debug::DEBUG_MODE = true;
	signal(SIGINT, &SignalHandler::sigHandlerInt);
	if (ac < 2)
		Logger::log(Logger::Error, "Usage: ./nanotekspice file [Options]", true);
	nts::Lexer::readFileAndArguments(av, parser);
	StandardInput::getStandardInput(parser);
	return (0);
}


