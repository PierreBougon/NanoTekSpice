//
// Created by Pierre Bougon on 04/02/17.
//

#ifndef NANOTEKSPICE_SIGNALHANDLER_H_
#define NANOTEKSPICE_SIGNALHANDLER_H_

extern int g_interuptLoop;

class SignalHandler
{
public:
    static void sigHandlerInt(int sig);
};


#endif // !NANOTEKSPICE_SIGNALHANDLER_H_
