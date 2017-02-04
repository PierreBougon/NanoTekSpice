//
// Created by Pierre Bougon on 01/02/17.
//

#include <iostream>
#include <Logger.h>

int main(int ac, char **av)
{
    Debug::DEBUG_MODE = true;
    if (ac < 2)
        Logger::log(Logger::Error, "Usage: ./nanotekspice file [Options]");
    return (0);
}