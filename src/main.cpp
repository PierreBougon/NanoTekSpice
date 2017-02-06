//
// Created by Pierre Bougon on 01/02/17.
//

#include <iostream>
#include <Logger.h>
#include <signal.h>
#include <SignalHandler.h>

int main(int ac, char **av)
{
    Debug::DEBUG_MODE = true;
    signal(SIGINT, &SignalHandler::sigHandlerInt);
    if (ac < 2)
        Logger::log(Logger::Error, "Usage: ./nanotekspice file [Options]");
    return (0);
}