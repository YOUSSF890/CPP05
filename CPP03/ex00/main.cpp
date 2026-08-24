#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Jack");
    
    a.attack("Enemy");
    a.takeDamage(5);
    a.beRepaired(3);
    a.takeDamage(10);
    a.attack("Enemy");
    a.beRepaired(5);
    std::cout << "\n--- Test Energy ---\n";
    ClapTrap b("Bob");
    for (int i = 0; i < 11; i++)
        b.attack("Target");
    
    return 0;
}

