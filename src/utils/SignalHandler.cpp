//
// Created by Pierre Bougon on 04/02/17.
//

#include <csignal>
#include <iostream>
#include "utils/SignalHandler.h"

int g_interuptLoop = 0;

void SignalHandler::sigHandlerInt(int sig) {
	if (sig == SIGINT) {
		g_interuptLoop = 1;
	}
}
