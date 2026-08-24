#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== FragTrap Construction Test ===" << std::endl;
    {
        FragTrap f("Alex");
    }
    
    std::cout << "\n=== FragTrap Functionality Test ===" << std::endl;
    FragTrap warrior("Warrior");
    warrior.attack("Enemy");
    warrior.takeDamage(40);
    warrior.beRepaired(20);
    warrior.highFivesGuys();
    
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    FragTrap copy(warrior);
    copy.highFivesGuys();
    
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    FragTrap assigned("Temp");
    assigned = warrior;
    assigned.highFivesGuys();
    
    std::cout << "\n=== Comparison: ClapTrap vs ScavTrap vs FragTrap ===" << std::endl;
    ClapTrap c("Clappy");
    ScavTrap s("Scavvy");
    FragTrap f2("Fraggy");
    
    std::cout << "\n--- Attacks ---" << std::endl;
    c.attack("Target");
    s.attack("Target");
    f2.attack("Target");
    
    std::cout << "\n--- Special Abilities ---" << std::endl;
    s.guardGate();
    f2.highFivesGuys();
    
    std::cout << "\n=== Destruction Chain Test ===" << std::endl;
    return 0;
}