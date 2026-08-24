#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << name << " Zombie destroyed\n";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
