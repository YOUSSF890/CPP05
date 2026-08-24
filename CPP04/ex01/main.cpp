#include "Cat.hpp"
#include "Dog.hpp"



int main()
{
    int SIZE = 10;
    Animal* animals[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << animals[i]->getType() << "\n";
        animals[i]->makeSound();
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete animals[i];
    }

    std::cout << "\n---------------- copy constructor ----------------\n";
    {
        Dog a;
        Dog b;        
        a = b;
    }
    std::cout << "\n---------------------------------------------------\n";
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }

}
