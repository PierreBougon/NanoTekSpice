//
// Created by Pierre Bougon on 03/02/17.
//

#include <iostream>
#include "Logger.h"

bool Debug::DEBUG_MODE;

void Logger::log(Logger::Level lvl, std::string msg, bool abort)
{
    switch (lvl)
    {
        case Logger::DEBUG:
            if (Debug::DEBUG_MODE)
                std::cout << "<Debug> : " << msg << std::endl;
            break;
        case Logger::Info:
            std::cout << "<Info> : " << msg << std::endl;
            break;
        case Logger::Warning:
            std::cerr << "<Warning> : " << msg << std::endl;
            break;
        case Logger::Error:
            std::cerr << "<Error> : " << msg << std::endl;
            if (abort)
                std::abort();
            break;
    }
}
