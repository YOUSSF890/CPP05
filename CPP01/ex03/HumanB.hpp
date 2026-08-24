#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *club;
    public:
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon& club);
};

#endif