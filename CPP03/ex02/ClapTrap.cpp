#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "X";
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << "Default constructor ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << "ClapTrap " << name << " is created!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    name = other.name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    std::cout << "Copy constructor ClapTrap called" << std:: endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        Hit_points = other.Hit_points;
        Energy_points = other.Energy_points;
        Attack_damage = other.Attack_damage;
    }
    std::cout << "Copy assignment operator ClapTrap called" << std::endl;
    return *this;
}


void ClapTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0) {   
        Energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!\n";
    }
    else
        std::cout << "ClapTrap " << name << " cannot attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points == 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair!\n";
        return ;
    }
    if (Hit_points > amount)
        Hit_points -= amount;
    else
        Hit_points = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! (HP = " << Hit_points << ")\n";
    
}


void ClapTrap::beRepaired(unsigned int amount)
{
    
    if (Hit_points == 0 || Energy_points == 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair!\n";
        return;
    }
    Energy_points--;

    if (Hit_points > UINT_MAX - amount)
        Hit_points = UINT_MAX;
    else
        Hit_points += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points! (HP = " << Hit_points << ")\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destroyed!\n";
}
