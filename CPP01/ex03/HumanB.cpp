#include "HumanB.hpp"

void HumanB::attack()
{
    if (!club)
        return ;
    std::cout << name << " attacks with their " << club->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& club)
{
    this->club = &club;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->club = NULL;
}