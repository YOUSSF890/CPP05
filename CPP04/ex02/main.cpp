#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    // const Animal* meta = new Animal();error
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();


    delete j;
    delete i;
}