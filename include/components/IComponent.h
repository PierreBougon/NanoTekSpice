//
// Created by Pierre Bougon on 02/02/17.
//

#ifndef NANOTEKSPICE_ICOMPONENT_H_
#define NANOTEKSPICE_ICOMPONENT_H_


#include <string>
#include <cstddef>

namespace nts
{
    namespace Component
    {
        class InputPin;
    }
}

namespace nts
{
    enum Tristate
    {
        UNDEFINED   = (-true),
        TRUE        = true,
        FALSE       = false
    };

    class IComponent
    {
    public:
        virtual ~IComponent(){};

        // Compute value of the precised pin
        virtual nts::Tristate           Compute(size_t pin_num_this = 1) = 0;

        // Useful to link IComponent together
        virtual void                    SetLink(size_t pin_num_this,
                                                nts::IComponent &component, size_t
                                                pin_num_target) = 0;

        // Print on term the name of the component and the state of every pin of the
        // current component
        // The output won't be tested, but it may help you as a trace
        virtual void                    Dump(void) const = 0;

        // Useful to define gate used by Compute on OutputPin
        virtual nts::Tristate    gate(nts::Component::InputPin const *inputPin1,
                                      nts::Component::InputPin const *inputPin2)
        const = 0;

        virtual void onSimulationFinished() = 0;
    };

}


#endif // !NANOTEKSPICE_ICOMPONENT_H_
