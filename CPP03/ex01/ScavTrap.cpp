#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "Default constructor ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0) {   
        Energy_points--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!\n";
    }
    else
        std::cout << "ScavTrap " << name << " cannot attack!\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->name = name;
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap "<< name << " is created!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor ScavTrap called" << std:: endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << name << " is destroyed!\n";
}