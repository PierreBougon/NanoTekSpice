//
// Created by Pierre Bougon on 14/02/17.
//

#include "components/CTrue.h"

nts::Component::CTrue::CTrue(const std::string &name) : CInput(name)
{
    setState(nts::TRUE);
}

nts::Component::CTrue::~CTrue()
{

}
