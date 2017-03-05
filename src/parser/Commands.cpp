//
// Created by peau_c on 3/2/17.
//

#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include "utils/SignalHandler.h"
#include "parser/Commands.h"
#include "components/COutput.h"

void nts::Commands::exitFunc(nts::Parser &parser) {
	(void)parser;
	exit(0);
}

std::string getAsciiTristateValue(nts::Tristate value) {
	if (value == nts::Tristate::FALSE)
		return ("0");
	else if (value == nts::Tristate::TRUE)
		return ("1");
	return ("U");
}

void nts::Commands::display(nts::Parser &parser) {
	for(std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin();
		it < parser.getComponentList().end(); ++it) {
		if (dynamic_cast<nts::Component::COutput *> (*it) != nullptr) {
			std::cout << (*it)->getName() << "=" + (getAsciiTristateValue((*it)->getStateAt())) << std::endl;
		}
	}
}

void nts::Commands::simulate(nts::Parser &parser) {
	for(std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin(); it < parser.getComponentList().end(); ++it) {
		for (size_t i = 0; i < (*it)->getNumPin(); ++i) {
			if ((dynamic_cast<nts::Component::AComponent *>(*it))->getPinAt(i)->getType() == nts::Component::PinType::output) {
				(*it)->Compute(i);
			}
		}
	}
	for(std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin();
		it < parser.getComponentList().end(); ++it) {
		if (dynamic_cast<nts::Component::COutput *> (*it) != nullptr) {
			while (true)
				try {
					(*it)->Compute();
				}
				catch (std::out_of_range e) {
					break;
				}
		}
	}
	for (std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin(); it < parser.getComponentList().end(); ++it) {
		(*it)->onSimulationFinished();
	}
}



void nts::Commands::loop(nts::Parser &parser) {
	signal(SIGINT, SignalHandler::sigHandlerInt);
	while (!g_interuptLoop) {
		simulate(parser);
	}
	g_interuptLoop = 0;
}

void nts::Commands::dump(nts::Parser &parser) {
	for(std::vector<nts::IComponent *>::const_iterator it = parser.getComponentList().begin();
		it < parser.getComponentList().end(); ++it)
		(*it)->Dump();
}

