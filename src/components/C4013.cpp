//
// Created by Pierre Bougon on 06/02/17.
//

#include "components/pins/ClockedPin.h"
#include "components/pins/BasicPin.h"
#include "components/C4013.h"

nts::Component::C4013::C4013(const std::string &name) : AComponent(name)
{
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new ClockedPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(nullptr);
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new ClockedPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
    pinList.push_back(new BasicPin());
}

nts::Tristate nts::Component::C4013::gate(nts::Component::InputPin const *inputPin1,
                                          nts::Component::InputPin const *inputPin2) const
{
    return UNDEFINED;
}

nts::Component::C4013::~C4013()
{

}

nts::Tristate nts::Component::C4013::Compute(size_t pin_num_this)
{
    int num = 0;

    if (pin_num_this == 0 || pin_num_this == 1)
        num = 1;
    else if (pin_num_this == 11 || pin_num_this == 12)
        num = 2;
    else
        return (_getPinAt(pin_num_this)->compute(*this));

    if (getClock(num)->getClockState() == ClockState::Up && getData(num)->getState() == 0
        && getReset(num)->getState() == 0 && getSet(num)->getState() == 0)
    {
        getQ(num)->setState(FALSE);
        getQbar(num)->setState(TRUE);
    }
    else if (getClock(num)->getClockState() == ClockState::Up && getData(num)->getState() == 1
             && getReset(num)->getState() == 0 && getSet(num)->getState() == 0)
    {
        getQ(num)->setState(TRUE);
        getQbar(num)->setState(FALSE);
    }
    else if (getClock(num)->getClockState() == ClockState::Down
             && getReset(num)->getState() == 0 && getSet(num)->getState() == 0)
    {
        getQ(num)->setState(getQ(num)->getPrevState());
        getQbar(num)->setState(getQbar(num)->getPrevState());
    }
    else if (getReset(num)->getState() == 1 && getSet(num)->getState() == 0)
    {
        getQ(num)->setState(FALSE);
        getQbar(num)->setState(TRUE);
    }
    else if (getReset(num)->getState() == 0 && getSet(num)->getState() == 1)
    {
        getQ(num)->setState(TRUE);
        getQbar(num)->setState(FALSE);
    }
    else if (getReset(num)->getState() == 1 && getSet(num)->getState() == 1)
    {
        getQ(num)->setState(TRUE);
        getQbar(num)->setState(TRUE);
    }
    return getPinAt(pin_num_this)->getState();
}

nts::Component::BasicPin *nts::Component::C4013::getData(int num)
{
    if (num == 1)
        return dynamic_cast<BasicPin *>(_getPinAt(4));
    else if (num == 2)
        return dynamic_cast<BasicPin *>(_getPinAt(8));
    else
        return nullptr;
}

nts::Component::BasicPin *nts::Component::C4013::getReset(int num)
{
    if (num == 1)
        return dynamic_cast<BasicPin *>(_getPinAt(3));
    else if (num == 2)
        return dynamic_cast<BasicPin *>(_getPinAt(9));
    else
        return nullptr;
}

nts::Component::BasicPin *nts::Component::C4013::getSet(int num)
{
    if (num == 1)
        return dynamic_cast<BasicPin *>(_getPinAt(5));
    else if (num == 2)
        return dynamic_cast<BasicPin *>(_getPinAt(7));
    else
        return nullptr;
}

nts::Component::ClockedPin *nts::Component::C4013::getClock(int num)
{
    if (num == 1)
        return dynamic_cast<ClockedPin *>(_getPinAt(2));
    else if (num == 2)
        return dynamic_cast<ClockedPin *>(_getPinAt(10));
    else
        return nullptr;
}

nts::Component::BasicOutputPin *nts::Component::C4013::getQ(int num)
{
    if (num == 1)
        return dynamic_cast<BasicOutputPin *>(_getPinAt(0));
    else if (num == 2)
        return dynamic_cast<BasicOutputPin *>(_getPinAt(12));
    else
        return nullptr;
}

nts::Component::BasicOutputPin *nts::Component::C4013::getQbar(int num)
{
    if (num == 1)
        return dynamic_cast<BasicOutputPin *>(_getPinAt(1));
    else if (num == 2)
        return dynamic_cast<BasicOutputPin *>(_getPinAt(11));
    else
        return nullptr;
}
