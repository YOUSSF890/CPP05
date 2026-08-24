#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();


    std::cout << "\n----------- makeSound -------------\n" << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n----------- copy constructor -------------\n" << std::endl;
    {
        const Animal obj(*j);
        obj.makeSound();
    }
    std::cout << "\n----------- copy assignment operator -------------\n" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        dog2 = dog1;
    }
    std::cout << "\n----------- Do not use virtual -------------\n" << std::endl;
    {
        WrongAnimal *obj1 = new WrongAnimal;
        WrongAnimal *obj2 = new WrongCat();

        std::cout << obj1->getType() << " " << std::endl;
        std::cout << obj2->getType() << " " << std::endl;
        obj1->makeSound();
        obj2->makeSound();
        delete obj1;
        delete obj2;
    }

    std::cout << "\n----------- Destructor -------------\n" << std::endl;
    delete meta;
    delete j;
    delete i;

    return 0;
}
