//
// Created by Pierre Bougon on 01/03/17.
//

#include "components/pins/ClockedPin.h"

nts::Tristate nts::Component::ClockedPin::getState() const
{
    Tristate tmp = BasicPin::getState();
    updateClockState(tmp);
    return tmp;
}

nts::Component::ClockState nts::Component::ClockedPin::getClockState() const
{
    return clockState;
}

nts::Tristate nts::Component::ClockedPin::compute(const nts::IComponent &component)
{
    Tristate tmp = BasicPin::compute(component);
    updateClockState(tmp);
    return tmp;
}

void nts::Component::ClockedPin::updateClockState(nts::Tristate state) const
{
    if (state == UNDEFINED)
        clockState = ClockState::Unknown;
    else if (state == TRUE && clockState != ClockState::Up)
        clockState = ClockState::Up;
    else if (state == FALSE && clockState != ClockState::Down)
        clockState = ClockState::Down;
    else
        clockState = ClockState::Unknown;
}

nts::Component::ClockedPin::ClockedPin()
        : BasicPin(), clockState(ClockState::Unknown)
{}
