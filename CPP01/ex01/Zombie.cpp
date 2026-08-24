#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
     std::cout << "Zombie destroyed\n";
}

void Zombie::setname(std::string name)
{
    this->name = name;
}


void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}