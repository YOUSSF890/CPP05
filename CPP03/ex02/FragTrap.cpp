#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "Default constructor FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->name = name;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap " << name << " is created!\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor FragTrap called" << std:: endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "Copy assignment operator FragTrap called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " is destroyed!\n";
}

