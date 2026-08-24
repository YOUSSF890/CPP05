#include "Zombie.hpp"

int main()
{
    int i = 0;
    int N = 5;
    Zombie *zombie = zombieHorde(N,"youssef");
    if (!zombie)
        return 1;
    while (i < N)
    {
        zombie[i].announce();
        i++;
    }
    delete[] zombie;
    return (0);

}