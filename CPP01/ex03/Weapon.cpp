#include "HumanB.hpp"

void Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    return (type);
}

Weapon::Weapon(std::string type)
{
    setType(type);
}