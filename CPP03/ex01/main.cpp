#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    std::cout << "=== Construction Chain Test ===" << std::endl;
    {
        ScavTrap s("Guardian");
    }
    
    std::cout << "\n=== Attack Test ===" << std::endl;
    ScavTrap s1("Warrior");
    s1.attack("Enemy");
    s1.takeDamage(30);
    s1.beRepaired(10);
    s1.guardGate();
    
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    ScavTrap s2(s1);
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    ScavTrap s3("Defender");
    s3 = s1;
    
    std::cout << "\n=== Destruction Chain Test ===" << std::endl;
    return 0;
}