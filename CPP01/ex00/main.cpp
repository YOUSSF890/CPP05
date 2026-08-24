#include "Zombie.hpp"

int main()
{
    Zombie *zombi = newZombie("Youssef");
    zombi->announce();
    randomChump("abdo");
    delete zombi;
}

