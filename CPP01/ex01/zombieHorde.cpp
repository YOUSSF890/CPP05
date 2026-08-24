#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;
    if (N <= 0)
        return NULL;
    
    Zombie *zombie;
    zombie = new Zombie[N];

    while (i < N)
    {
        zombie[i].setname(name);
        i++;
    }
    return (zombie);
}
